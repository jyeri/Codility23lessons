// Write a function
// 
// int solution(int A[], int N);


// 
// that, given an array A consisting of N integers, returns the number of distinct values in array A.
// 
// For example, given array A consisting of six elements such that:
// 
//  A[0] = 2    A[1] = 1    A[2] = 1
//  A[3] = 2    A[4] = 3    A[5] = 1
// the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

// first idea would be to sort elements from smallest to highest and then discard the doubles. this is highy unefficient
// using qsort might be better? then counting the element that are different

#include <stdlib.h>

int comp(void *a, void *b)
{
    return *(int*)a - *(int*)b;
}

int solution(int A[], int N)
{
    int x = 1;
    int counter = 0;
    if (N == 1)
        return 1;
    qsort(A, N, sizeof(int), (int *)comp);
    while(x <= N)
    {
        if (A[x] != A[x-1])
            counter++;
        x++;
    }
    return counter;
}

//problem with one off? == means if there is only one element. fixed on line 29.