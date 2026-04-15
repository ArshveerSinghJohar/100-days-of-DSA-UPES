#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 50

// Comparator for sorting strings
int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    char votes[MAX][LEN];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    // Sort the votes
    qsort(votes, n, sizeof(votes[0]), cmp);

    int maxCount = 1, count = 1;
    char winner[LEN];
    strcpy(winner, votes[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(votes[i], votes[i - 1]) == 0) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                strcpy(winner, votes[i - 1]);
            }
            count = 1;
        }
    }

    // Check last candidate
    if (count > maxCount) {
        maxCount = count;
        strcpy(winner, votes[n - 1]);
    }

    printf("%s %d\n", winner, maxCount);

    return 0;
}