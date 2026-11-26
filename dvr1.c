#include<stdio.h>
int main(){
    int dist[10][10],cost[10][10];
    int n,i,j,k;
    printf("Enter number of routers: ");
    scanf("%d",&n);
    printf("Enter the cost matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            dist[i][j]=cost[i][j];
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    printf("Routing table:\n");
    for(i=0;i<n;i++){
        printf("Router %d : \n",i+1);
        for(j=0;j<n;j++){
            printf("To router %d : %d\n",j+1,dist[i][j]);
        }
    }
    return 0;
}