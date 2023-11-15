

// first idea is again to sort array, then go from there


// fixes: Bandage fix for max and min ints, so we no overflow
// also fixed the conditions for triangle, i must have been sleeping on last commit
#include <stdlib.h>

int comp(void *a, void *b)
{
    return *(long*)a - *(long*)b;
}

int solution(int A[], int N)
{
    int i = 0;
    long long1 = 0;
    long long2 = 0;
    long long3 = 0;
    // sort the stack
    qsort(A, N, sizeof(int), (int *)comp);
    // iterate the stack
    while (i < N - 2)
    {
        // check if conditions are met for ret 1
        long1 = A[i];
        long2 = A[i + 1];
        long3 = A[i + 2];
        if (long1 + long2 > long3 && long3 >= 0 && long1 >= 0 && long2 >= 0)
            return 1;
        i++;
    }
    // else return 0
    return 0;
}