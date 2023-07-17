#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, cost[10][10], mincost = 0, ne = 1;
    int visited[10], u, v, min;

    printf("Size: ");
    scanf("%d", &n);

    printf("Nodes:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    visited[1] = 1;

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] == 0)
                        continue;
                    else {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {
            printf("%d edge (%d, %d) = %d\n", ne++, u, v, min);
            mincost = mincost + min;
            visited[v] = 1;
        }

        cost[u][v] = cost[v][u] = 999;
    }

    printf("Minimum cost: %d\n", mincost);

    return 0;
}
