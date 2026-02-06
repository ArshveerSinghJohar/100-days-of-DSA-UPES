#include <stdio.h>

int main() {
    int p, q;
    int A[100], B[100];
    int i = 0, j = 0;

   
    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    printf("Enter arrival times for server log 1:\n");
    for (i = 0; i < p; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    printf("Enter arrival times for server log 2:\n");
    for (i = 0; i < q; i++) {
        scanf("%d", &B[i]);
    }

    
    i = 0;
    j = 0;

    printf("Merged chronological log:\n");

    while (i < p && j < q) {
        if (A[i] <= B[j]) {
            printf("%d ", A[i]);
            i++;
        } else {
            printf("%d ", B[j]);
            j++;
        }
    }

 
    while (i < p) {
        printf("%d ", A[i]);
        i++;
    }

    while (j < q) {
        printf("%d ", B[j]);
        j++;
    }

    return 0;
}
