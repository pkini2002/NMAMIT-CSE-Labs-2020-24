#include <stdio.h>
#include <stdlib.h>

int cannotbePalced(int k,int col[]){
for(int i=1;i<=k-1;i++)
    if(col[k]==col[i] || (abs(i-k)==abs(col[i]-col[k])))
        return 1;
return 0;
}

int NQueen(int n){
int k=1; //Number of queens
int col[n+1],i,j;
int count=0;
col[k]=0;
while(k!=0){
    col[k]=col[k]+1;
    while(col[k]<=n && cannotbePalced(k,col)){
        col[k]=col[k]+1;
    }
    if(col[k]<=n){
        if(k==n){
            count++;
            printf("Count is %d\n",count);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)
                    if(col[i]==j)
                        printf("Q%d ",i);
                    else
                        printf(" * ");
                    printf("\n");

            }
            printf("\n");
        }
        else{
            k++;
            col[k]=0;
        }
    }
    else
        k--;
}
return count;
}

int main()
{
    int n,solution;
    solution=0;
    printf("Enter the number of Queens: \n");
    scanf("%d",&n);
    solution=NQueen(n);
    if(solution==-1){
        printf("No solutions exists!");
    }
    return 0;
}
