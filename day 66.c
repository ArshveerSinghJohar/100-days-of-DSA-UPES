#include <stdio.h>

#define MAX 100

int visited[MAX];
int recStack[MAX];

// DFS function
int dfs(int node, int n, int adj[MAX][MAX]) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            // If not visited → recurse
            if (!visited[i]) {
                if (dfs(i, n, adj))
                    return 1;
            }
            // If in recursion stack → cycle
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    // Remove from recursion stack
    recStack[node] = 0;
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

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int hasCycle = 0;

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n, adj)) {
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