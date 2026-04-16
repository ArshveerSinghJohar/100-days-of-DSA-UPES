#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

// Simple hash map using arrays (since constraints are manageable)
typedef struct {
    int sum;
    int index;
} Hash;

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0, maxLen = 0;

    // Initialize hash table
    Hash hash[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: prefix sum becomes 0
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Check if prefixSum seen before
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (hash[j].sum == prefixSum) {
                int len = i - hash[j].index;
                if (len > maxLen) {
                    maxLen = len;
                }
                found = 1;
                break;
            }
        }

        // If not found, store it
        if (!found) {
            hash[size].sum = prefixSum;
            hash[size].index = i;
            size++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}