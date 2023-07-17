#include <stdio.h>

int parent[10];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

int unionSets(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, a[10][10], ne = 1, n, mincost = 0, min, u, v;

    printf("nodes: ");
    scanf("%d", &n);

    printf("metrics:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                a[i][j] = 999;
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (ne < n) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] < min) {
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        u = find(u);
        v = find(v);
        if (unionSets(u, v)) {
            printf("%d edge (%d,%d) = %d\n", ne++, u, v, min);
            mincost = mincost + min;
        }

        a[u][v] = a[v][u] = 999;
    }

    printf("Minimum Cost: %d\n", mincost);

    return 0;
}
