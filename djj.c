#include<stdio.h>
#define inf 9999
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
    int st=0,min,u;
    for(int i=0;i<n;i++){
        dist[i]=inf;
    }
    dist[st]=0;
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
            if(graph[u][j]!=0 && !visited[j] && graph[u][j]+dist[u]<dist[j]){
                dist[j]=graph[u][j]+dist[u];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i!=0){
            printf("Distance from %d to %d is: %d\n",st,i,dist[i]);
        }
    }
    return 0;
}