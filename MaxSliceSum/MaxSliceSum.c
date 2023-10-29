// A non-empty array A consisting of N integers is given. 
// A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. 
// The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].
// 
// Write a function:
// 
// int solution(int A[], int N);
// 
// that, given an array A consisting of N integers, returns the maximum sum of any slice of A.
// 
// For example, given array A such that:
// 
// A[0] = 3  A[1] = 2  A[2] = -6
// A[3] = 4  A[4] = 0
// the function should return 5 because:
// 
// (3, 4) is a slice of A that has sum 4,
// (2, 2) is a slice of A that has sum −6,
// (0, 1) is a slice of A that has sum 5,
// no other slice of A has sum greater than (0, 1).

// FIX LIST:
// NEGATIVES -> fixed with using bool instead of int as condition, next problem is negatives that doesnt make the slice too small
// SAW

int solution(int A[], int N)
{
    int maxslice = -2147483648;
    int i = 0;
    int min = 0;
    bool minset = false;

    // iterate array
    while (i < N)
    {
//        printf("min: %d, maxs: %d, A[i]: %d, i: %d \n", min, maxslice, A[i], i);
        // save new starting slice
        if (minset == false)
        {
            min = A[i];
            minset = true;
        }
        else
        {
 //           printf("ADDING: %d + %d ", min, A[i]);
            min = min + A[i];
 //           printf("= %d \n", min);
        }
        // save possible new maxslice
        if (min > maxslice)
            maxslice = min;
        if (A[i] < 0)
        {
            min = 0;
            minset = false;
        }
        i++;
    }
    return maxslice;

}