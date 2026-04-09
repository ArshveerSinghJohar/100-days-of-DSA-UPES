#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX];
    int indegree[MAX] = {0};

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Compute indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    // Kahn's Algorithm
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Cycle detection
    if (count != n) {
        printf("\nGraph has a cycle\n");
    }

    return 0;
}