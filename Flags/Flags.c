// A non-empty array A consisting of N integers is given.
// 
// A peak is an array element which is larger than its neighbours. 
// More precisely, it is an index P such that 0 < P < N − 1 and A[P − 1] < A[P] > A[P + 1].
// 
// For example, the following array A:
// 
//     A[0] = 1
//     A[1] = 5
//     A[2] = 3
//     A[3] = 4
//     A[4] = 3
//     A[5] = 4
//     A[6] = 1
//     A[7] = 2
//     A[8] = 3
//     A[9] = 4
//     A[10] = 6
//     A[11] = 2
// has exactly four peaks: elements 1, 3, 5 and 10.
// 
// You are going on a trip to a range of mountains whose relative heights are represented by array A, as shown in a figure below. 
// You have to choose how many flags you should take with you. 
// The goal is to set the maximum number of flags on the peaks, according to certain rules.
// 
// 
// 
// Flags can only be set on peaks. What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K. 
// The distance between indices P and Q is the absolute value |P − Q|.
// 
// For example, given the mountain range represented by array A, above, with N = 12, if you take:
// 
// two flags, you can set them on peaks 1 and 5;
// three flags, you can set them on peaks 1, 5 and 10;
// four flags, you can set only three flags, on peaks 1, 5 and 10.
// You can therefore set a maximum of three flags in this case.
// 
// Write a function:
// 
// int solution(int A[], int N);
// 
// that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.

// this solution is 33%, fails in various cases. back to drawing board
// -> could try makeing "bool matrix of the peaks -> checking is faster?"

// this solution still only 40%, its most of the time 3 under of wanted, find out why?

#include <math.h>
#include <stdbool.h>

int solution(int A[], int N) 
{
    long i = 1;
    int flags = 0;
    int peaks = 0;
    int result = 0;
    int traveldistance = 0;
    bool mat[N];

    //if there is less than 3 point, there are no peaks
    if (N < 3)
        return 0;
    //create bool array of peaks for fast check, set 1st and last elemnt to false since they arent peaks
    while (i < N - 1)
    {
        if (A[i] > fmax(A[i - 1], A[i + 1]))
        {
            //this is a peak
            mat[i] = true;
            peaks += 1;
        }
        else 
        {
            //not a peak, set to false
            mat[i] = false;
        }
        i++;
    }
    mat[0] = false;
    mat[N - 1] = false;

    //calculate most flags needed, min(sqrt(n), peaks)
    flags = fmin(sqrt(N), peaks);
    traveldistance = flags;
    //iterate the bool, try to place flag on peak -> move by amount of flags to skip
    i = 1;
    while (i < N - 1 && flags > 0) 
    {
        if (mat[i])
        {
            //place a flag, pump result, and travel by max flags
            result += 1;
            flags -= 1;
            i += traveldistance;
        }
        else 
        {
            //not a peak, go to next point
            i += 1;
        }
    }
    return result;
}