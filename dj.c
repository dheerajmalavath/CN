#include<stdio.h>
#define inf 999
#define n 7
int main(){
    int graph[n][n] = {
        {0, 0, 1, 2, 0, 0, 0},
        {0, 0, 2, 0, 0, 3, 0},
        {1, 2, 0, 1, 3, 0, 0},
        {2, 0, 1, 0, 0, 0, 1},
        {0, 0, 3, 0, 0, 2, 0},
        {0, 3, 0, 0, 2, 0, 1},
        {0, 0, 0, 1, 0, 1, 0}
    };
    int dist[n],visited[n]={0};
    int start,min,u;
    printf("Enter starting vertex: ");
    scanf("%d",&start);
    for(int i=0;i<n;i++){
        dist[i]=inf;
    }
    dist[start]=0;
    for(int i=0;i<n;i++){
        min=inf;
        u=-1;
        for(int j=0;j<n;j++){
            if(!visited[j] && dist[j]<min){
                min=dist[j];
                u=j;
            }
        }

        if(u==-1) break;
        visited[u]=1;
        for(int j=0;j<n;j++){
            if(graph[u][j]!=0 && !visited[j] && dist[u]+graph[u][j]<dist[j]){
                dist[j]=dist[u]+graph[u][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i!=start){
            printf("Distance from %d to %d is: %d\n",start,i+1,dist[i]);
        }
    }
    return 0;

}