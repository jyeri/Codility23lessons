// You are given an array A consisting of N integers.
// 
// For each number A[i] such that 0 ≤ i < N, we want to count the number of elements of the array that are not the divisors of A[i]. We say that these elements are non-divisors.
// 
// For example, consider integer N = 5 and array A such that:
// 
//     A[0] = 3
//     A[1] = 1
//     A[2] = 2
//     A[3] = 3
//     A[4] = 6
// For the following elements:
// 
// A[0] = 3, the non-divisors are: 2, 6,
// A[1] = 1, the non-divisors are: 3, 2, 3, 6,
// A[2] = 2, the non-divisors are: 3, 3, 6,
// A[3] = 3, the non-divisors are: 2, 6,
// A[4] = 6, there aren't any non-divisors.
// Assume that the following declarations are given:
// 
// struct Results {
//   int * C;
//   int L; // Length of the array
// };
// 
// Write a function:
// 
// struct Results solution(int A[], int N);
// 
// that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.
// 
// Result array should be returned as a structure Results.

// first idea is ofcourse brute forcing it one by one. but there is probably more efficient way
// holding separate array of times that that number occurs in orginal array?
// the we could just iterate the array and add all the divisors from another array?
// something like this:

// mad code bit more clear to me atleast, added some comments and deleted extra allocation. still 100%

struct Results solution(int A[], int N)
{
    struct Results  res;
    int *amount;
    int divisoramt = 0;
    int *resarr;
    int i = 0;
    int j = 1;

    // array for amount of occurances of number
    amount = (int *)calloc(2 * N + 1, sizeof(int));
    // array for results
    resarr = (int *)calloc(N + 1, sizeof(int));

    // loop to add occuranses of different numbers
    while (i < N)
    {
        amount[A[i]] = amount[A[i]] + 1;
        i++;
    }
    i = 0;

    // count divisors
    while (i < N)
    {
        divisoramt = 0;
        j = 1;
        // j < sqrt value at index
        while (j * j <= A[i])
        {
            //if dividable
            if (A[i] % j == 0)
            {
                //add divisors from count
                divisoramt += amount[j];
                if (A[i] / j != j)
                {
                    divisoramt += amount[A[i] / j];
                }
            }
            j++;
        }
        // add divisors to the result array and go in to the next element
        resarr[i] = N - divisoramt;
        i++;
    }

    res.L = N;
    res.C = resarr;
    free(amount);

    return res;
}