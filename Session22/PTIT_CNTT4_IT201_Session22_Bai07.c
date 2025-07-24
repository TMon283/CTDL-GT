#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];

void BFS(int start, int n) {
    int queue[MAX], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    if (v <= 0 || e <= 0 || v >= 100 || e >= 100) {
        printf("Invalid input\n");
        return 1;
    }
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        graph[u][w] = 1;
        graph[w][u] = 1;
    }

    int start;
    scanf("%d", &start);
    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);
    BFS(start, v);
    printf("\n");
    return 0;
}