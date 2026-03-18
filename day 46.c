#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue for level order
struct Node* queue[100];
int front = 0, rear = 0;

// Enqueue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* current = dequeue();

        // Left child
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    front = rear = 0;
    enqueue(root);

    while (front < rear) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left)
            enqueue(temp->left);
        if (temp->right)
            enqueue(temp->right);
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}