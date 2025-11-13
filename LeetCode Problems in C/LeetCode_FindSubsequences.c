/*
Name: Blaine Swieder
LeetCode (C): Find Subsequence of Length k with the Largest Sum
Date: June 28th, 2025
*/

#include <stdio.h>
#include <stdlib.h>

// Helpers

typedef struct {
    int value; // Element Value
    int index; // Original Position in Array
} Pair; 

// Sort Value by Value (Descending)

static int cmp_val_desc(const void *a, const void *b){
    const Pair *pa = (const Pair *)a;
    const Pair *pb = (const Pair *)b;
    return (pb -> value - pa -> value); // Pair bigger values first
}

// Sort by Original Index (ascending) 

static int cmp_idx_asc(const void *a, const void *b){
    const Pair *pa = (const Pair *)a;
    const Pair *pb = (const Pair *)b;
    return (pa -> index - pb -> index); // Restore Original Order
}


// Core Solution

int *maxSubsequence(const int *nums, int numsSize, int k, int *returnSize){
    // Step 1: Pair every value with its index
    Pair *pairs = malloc(numsSize * sizeof(Pair));
    if (!pairs) { perror("malloc"); exit(EXIT_FAILURE); } 
    for (int i = 0; i < numsSize; ++i){
        pairs[i].value = nums[i];
        pairs[i].index = i;
    }

    // Step 2: Pick the k largest values
    qsort(pairs, numsSize, sizeof(Pair), cmp_val_desc);

    Pair *top = malloc(k * sizeof(Pair));
    if (!top) { perror("malloc"); exit(EXIT_FAILURE); }
    for (int i = 0; i < k; ++i) top[i] = pairs[i];

    // Step 3: Restore original ordering among the k elements

    qsort(top, k, sizeof(Pair), cmp_idx_asc);

    // Step 4: Extract just the Values

    int *result = malloc(k * sizeof(int));
    if (!result) { perror("malloc"); exit(EXIT_FAILURE); }
    for (int i = 0; i < k; ++i) result[i] = top[i].value; 

    // Step 5: Clean Up and Return

    free(pairs); 
    free(top);
    *returnSize = k;
    return result;
}

int main(void) {
    int nums[] = {2, 1, 3, 3}; // Example Array
    int k = 2; // Length of Subsequence

    int outSize = 0; 
    int *subseq = maxSubsequence(nums, sizeof nums / sizeof nums[0], k, &outSize);

    printf("Max subsequence of length %d: [", k); 
    for (int i = 0; i < outSize; ++i){
        printf("%d%s", subseq[i], (i + 1 == outSize) ? "" : ", ");
    }

    printf("]\n");

    free(subseq);
    return 0;
}

















