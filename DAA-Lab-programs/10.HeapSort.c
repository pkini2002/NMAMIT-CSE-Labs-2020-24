#include <stdio.h>
#include <stdlib.h>

void HeapBottomUp(int H[],int n){
   int k,v;
   int heap;
   for(int i=(n/2);i>=1;i--){
    k=i;
    v=H[k];
    heap=0;
    while(!heap && 2*k<=n){
        int j=2*k;
        if(j<n){
            if(H[j]<H[j+1])
                j++;
        }
        if(v>=H[j])
            heap=1;
        else{
            H[k]=H[j];
            k=j;
        }
    }
    H[k]=v;
   }
}

void HeapSort(int H[],int n){
   int i;
   HeapBottomUp(H,n);
   for(i=n;i>=2;i--){
    H[1]=H[1]+H[i];
    H[i]=H[1]-H[i];
    H[1]=H[1]-H[i];
    HeapBottomUp(H,i-1);
   }
}

int main()
{
    int n;
    printf("Enter the array size: \n");
    scanf("%d",&n);
    int H[n+1];
    printf("Enter the array elements:\n");
    for(int i=1;i<=n;i++){
        scanf("%d",&H[i]);
    }
    printf("The array elements before sorting:\n");
    for(int i=1;i<=n;i++){
        printf("%d ",H[i]);
    }
    HeapSort(H,n);
    printf("\nThe array elements after sorting:\n");
    for(int i=1;i<=n;i++){
        printf("%d ",H[i]);
    }
    return 0;
}
