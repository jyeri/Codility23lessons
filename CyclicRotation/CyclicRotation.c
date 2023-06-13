#include <stdio.h>

struct  Results solution(int A[], int N, int K);
//
struct  Results
{
  int   *A;
  int   N; // Length of the array
};

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Results solution(int A[], int N, int K) 
{
    struct Results result;
    int hold;
    int i;
    int j;
    int size;
//  Declare variables needed and struct for result, also the declaring "copy variables" is just bad habit for not accidentally modifying something thats not supposed to.

    i = 0;
    j = 1;
    hold = 0;
    size = N;

 // This is Guard to empty array, or array of 1 number (should return as the same)
    if (N == 0 || N == 1)
    {
        result.A = A;
        result.N = N;
        return result;
    }

//  We rotate the array until the K is met (Not as optimized as it could be but something that i know that should work.)
    while (i < K)
    {
        hold = A[N - 1];
        while (j < N)
        {
            A[N - j] = A[N - j - 1];
            j++;
        }
        A[0] = hold;
        j = 0;
        i++;
    }
    
    result.A = A;
    result.N = size;
    return result;
}

// Basic main for test purposes
int main()
{
    int i = 1;
    struct Results final;
    int arr[] = {-1, -2, -3, -4, -5, -6};
    final = solution(arr, 6, 5);
    printf("size of final: %d\n", final.N);
    while(i < final.N)
    {
        printf("in the end:\n");
        printf("%d\n", final.A[i]);
        i++;
    }
    printf("in the end\n");
    return (0);
}
