#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define SIZE 100

int table[SIZE];

// Insert function
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Hash table full\n");
}

// Search function
void search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

// Main
int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}