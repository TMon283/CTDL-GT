#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, v;
    scanf("%d %d", &n, &v);

    if (n <= 0 || v <= 0 || n >= 100 || v >= 100) {
        printf("Invalid input\n");
        return 1;
    }
    int graph[100][100] = {0};
    int u, w;
    for (int i = 0; i < v; i++) {
        scanf("%d %d", &u, &w);
        graph[u][w] = 1;
        graph[w][u] = 1;
    }
    int k;
    scanf("%d", &k);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (graph[k][i] == 1) {
            count++;
        }
    }
    printf("So dinh ke voi %d la: %d\n", k, count);
    return 0;
}