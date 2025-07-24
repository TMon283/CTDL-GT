#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void DFS(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i, n);
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
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        graph[u][w] = 1;
        graph[w][u] = 1;
    }
    int start;
    scanf("%d", &start);
    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(start, v);
    printf("\n");
    return 0;
}