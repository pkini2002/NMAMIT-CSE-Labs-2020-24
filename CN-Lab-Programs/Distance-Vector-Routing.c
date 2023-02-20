#include <stdio.h>
#include <stdlib.h>

#define INFINITY 999

struct{
    int cost;
    int via;
}routeTable[10][10];

int n; // Number of nodes

void build_route_table(int i){
      int j,k,new_cost=0;
      for(j=0;j<n;j++){
        for(k=0;k<n && j!=i;k++){
            if(routeTable[i][j].cost != INFINITY){
                new_cost=routeTable[i][j].cost+routeTable[j][k].cost;

                if(routeTable[i][k].cost > new_cost){
                    routeTable[i][k].cost=new_cost;
                    routeTable[i][k].via=routeTable[i][j].via;
                }
            }
        }
      }
}

void find_path(int i,int j){
     printf("%c",'A'+i);

     if(i!=j){
        printf("-->");
        find_path(routeTable[i][j].via,j);
     }
}

void disp_route_table(int i){
     int j;
     printf("\n Final routing table for %c: ",'A'+i);
     printf("\n\t Destination\tCost\tOutgoing line");
     printf("\n\t----\t---\t----\n");

     for(j=0;j<n;j++){
        printf("\n\t\t%c",'A'+j);
        printf("\t%d",routeTable[i][j].cost);
        printf("\t%c",'A'+routeTable[i][j].via);
        printf("\n");
     }
}

void read_route_table(){
     int i,j;
     printf("Enter the initial routing table (if no direct node, enter 999)\n");
     for(i=0;i<n;i++){
        printf("\nRouting table for %c:\n",'A'+i);
        for(j=0;j<n;j++){
            if(i==j){
                routeTable[i][j].cost=0;
            }
            else{
                printf("-->%c:",'A'+j);
                scanf("%d",&routeTable[i][j].cost);
            }

            if(routeTable[i][j].cost != INFINITY)
                routeTable[i][j].via=j;
            else
                routeTable[i][j].via=INFINITY;
        }
     }
}

int main()
{
    int src,dest,i;
    int opt;
    printf("Enter the number of routers: \n");
    scanf("%d",&n);

    read_route_table();

    for(i=0;i<n;i++){
        build_route_table(i);
    }

    for(i=0;i<n;i++){
        disp_route_table(i);
        do{
            printf("\nEnter the source code (0 to %d): ",n-1);
            scanf("%d",&src);
            printf("Enter the destination node (0 to %d): ",n-1);
            scanf("%d",&dest);

            if(src > (n-1) || dest > (n-1)){
                printf("Router does not exist!\n");
            }
            else{
                find_path(src,dest);
                printf("\nThe cost of the shortest route is: %d\n",routeTable[src][dest].cost);
            }
            printf("Do you want to continue? (0/1): \n");
            scanf("%d",&opt);
        }while(opt);
    }
    return 0;
}
