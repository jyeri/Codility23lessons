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