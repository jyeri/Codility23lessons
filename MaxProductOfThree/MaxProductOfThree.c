// A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).
// 
// For example, array A such that:
// 
//   A[0] = -3
//   A[1] = 1
//   A[2] = 2
//   A[3] = -2
//   A[4] = 5
//   A[5] = 6
// contains the following example triplets:
// 
// (0, 1, 2), product is −3 * 1 * 2 = −6
// (1, 2, 4), product is 1 * 2 * 5 = 10
// (2, 4, 5), product is 2 * 5 * 6 = 60
// Your goal is to find the maximal product of any triplet.

//first thought: we are trying to find just 3 highest value ones?
// then its sort -> calculate
// forgot the double negative, so we have to check if A0 * A1 * A[n] is actually greater than 3 highest values.


#include <stdlib.h>

int comp(void *a, void *b)
{
    return *(int*)a - *(int*)b;
}

int solution(int A[], int N)
{
    if (N == 3)
        return A[0] * A[1] * A[2];
    qsort(A, N, sizeof(int), (int *)comp);
    long resbigs = A[N - 1] * A[N - 2] * A[N - 3];
    long reslows = A[0] * A[1] * A[N - 1];
    return resbigs > reslows ? resbigs : reslows;
}