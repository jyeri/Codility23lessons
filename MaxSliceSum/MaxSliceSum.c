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
// NEGATIVES -> fixed with using bool instead of int as condition, next problem is negatives that doesnt make the slice too small [3, -2, 3]
// SAW

// Fixed with fail checks for slices that dips in middle
// checked the perfect pdf, didnt understand shit since my own defined max() failed me.

int solution(int A[], int N)
{
    int i = 0;
    int max = 0;
    int slice = 0;
    // continue keeps fucking with my testing so ill make dump value that unused for real reasons (sorry)
    int dump = 0;

    while (i < N)
    {
        // if positive always just add on current slice
        if (A[i] > 0)
            slice = slice + A[i];
        else
        {
            // slice is 0 means we have not found starting position for slice or last one was < 0
            if (slice == 0)
                dump++; // this should be continue;
            // slice + index < 0 means not max slice can have this
            else if (slice + A[i] < 0)
                slice = 0;
            // add on the slice if it grows back up
            else
                slice = slice + A[i];
        }
        if (slice > max)
            max = slice;
        i++;
    }
    dump = 0; // just because
    return max;
}