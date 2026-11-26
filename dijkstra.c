
#include <stdio.h>
#define INF 9999
#define N 7

int main() {
    int graph[N][N] = {
        {0, 0, 1, 2, 0, 0, 0},
        {0, 0, 2, 0, 0, 3, 0},
        {1, 2, 0, 1, 3, 0, 0},
        {2, 0, 1, 0, 0, 0, 1},
        {0, 0, 3, 0, 0, 2, 0},
        {0, 3, 0, 0, 2, 0, 1},
        {0, 0, 0, 1, 0, 1, 0}
    };

    int dist[N], visited[N] = {0};
    int start, min, u;

    printf("Enter starting vertex (0-%d): ", N - 1);
    scanf("%d", &start);
    if (start < 0 || start >= N) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
        dist[i] = INF;

    dist[start] = 0;

    for (int i = 0; i < N; i++) {
        min = INF;
        u = -1;

        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int j = 0; j < N; j++) {
            if (graph[u][j] != 0 && !visited[j] &&
                dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i != start)
            printf("Distance from %d to %d = %d\n",
                   start, i, dist[i]);
    }

    return 0;
}
