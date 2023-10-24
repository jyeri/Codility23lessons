// An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
// 
// A[P] + A[Q] > A[R],
// A[Q] + A[R] > A[P],
// A[R] + A[P] > A[Q].
// For example, consider array A such that:
// 
//   A[0] = 10    A[1] = 2    A[2] = 5
//   A[3] = 1     A[4] = 8    A[5] = 20
// Triplet (0, 2, 4) is triangular.

// first idea is again to sort array, then go from there


#include <stdlib.h>

int comp(void *a, void *b)
{
    return *(int*)a - *(int*)b;
}

int solution(int A[], int N)
{
    int i = 2;
    // sort the stack
    qsort(A, N, sizeof(int), (int *)comp);
    // iterate the stack
    while (i <= N)
    {
        // check if conditions are met for ret 1
        if ((A[i - 2] + A[i - 1] > A[i]) && (A[i - 1] + A[i] > A[i - 2]) && (A[i - 2] + A[i] > A[i - 1]))
            return 1;
        i++;
    }
    // else return 0
    return 0;
}
