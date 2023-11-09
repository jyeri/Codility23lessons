// ended up doing it again. 100%
// there was stupid errors avoiding malloc

// functionality
// simply make new result array size on N + 1
// -> allocate it
// -> check what index value there is after rotations (K % N)
// -> assign those to new array
// -> return new array

#include <string.h>

struct Results solution(int A[], int N, int K) 
{
    struct Results result;
    int i;
    int *res;
    int newK;

    if (N < 2)
    {
        result.A = A;
        result.N = N;
        return result;
    }

    res = (int *)malloc(sizeof(int) * N + 1);
    memset(res, 0, sizeof(int));
    i = 0;
    newK = K % N;
    while (i < N)
    {
        if(i - newK < 0)
        {
            res[i] = A[N - newK + i];
        }
        else
        {
            res[i] = A[i - newK];
        }
//        printf("%d", res[i]);
        i++;
    }
    res[i] = '\0';
    result.A = res;
    result.N = N;
    return result;
}

// #include <stdio.h>
// 
// struct  Results solution(int A[], int N, int K);
// 
// struct  Results
// {
//   int   *A;
//   int   N; // Length of the array
// };


// Basic main for test purposes
// int main()
// {
//     int i = 1;
//     struct Results final;
//     int arr[] = {-1, -2, -3, -4, -5, -6};
//     final = solution(arr, 6, 5);
//     printf("size of final: %d\n", final.N);
//     while(i < final.N)
//     {
//         printf("in the end:\n");
//         printf("%d\n", final.A[i]);
//         i++;
//     }
//     printf("in the end\n");
//     return (0);
// }
