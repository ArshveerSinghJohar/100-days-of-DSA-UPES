#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int stack[MAX];
int top = -1;

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int node, int n, int adj[MAX][MAX]) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n, adj);
        }
    }

    // Push after visiting all neighbors
    push(node);
}

// Topological Sort
void topoSort(int n, int adj[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, adj);
        }
    }

    // Print stack (reverse order)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
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

    topoSort(n, adj);

    return 0;
}