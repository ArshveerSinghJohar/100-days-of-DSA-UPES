#include <stdio.h>

#define MAX 100

int visited[MAX];

// DFS function
int dfs(int node, int parent, int n, int adj[MAX][MAX]) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            // If not visited → recurse
            if (!visited[i]) {
                if (dfs(i, node, n, adj))
                    return 1;
            }
            // If visited and not parent → cycle
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX];

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int hasCycle = 0;

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n, adj)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}