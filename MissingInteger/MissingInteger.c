#include <stdbool.h>
#include <stdio.h>

// Write a function:
// 
// int solution(int A[], int N);
// 
// that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

// first thought is iterate array, and pump up the holder every time u see holder number in array. 
// problem with this: then you would have to reiterate again everytime you see the holder in array.
// Second thought is some how check what is missing between 0 and A[0], but same problem occurs.

// trying first with simplest method, got 66%

// int solution(int A[], int N)
// {
//     int x = 0;
//     int hold = 1;
//     while (x < N)
//     {
//         if (A[x] == hold)
//         {
//             hold++;
//             x = -1;
//         }
//         x++;
//     }
//     return hold;
// }

// second try i will try to cut down the iterations
// can cut down iterations making bool map of 0 to N numbers (1st iteration)
// then making map[x] = true for all positive integers (2nd iteration)
// then scanning true the map, and return the first false ? (3rd iteration)

// result: got 88, fails in one test featuring all the digits till 100000 ( expected 100001, got 100003, why?)
// Added new check to stop at latest to N + 1, shouldnt be the fix but got 100

#include <stdbool.h>
#include <stdio.h>

int solution(int A[], int N)
{
    int x = 0;
    bool map[N + 1];

    // make map of falses
    while (x < N)
    {
        map[x] = false;
        x++;
    }
    x = 0;

    //mark every number over 0 to true AND under N
    while (x < N)
    {
        if (A[x] > 0 && A[x] < N + 1)
            map[A[x]] = true;
        x++;
    }
    x = 1;
    //stop at first false and return
    while (map[x] == true && x < N + 1)
        x++;
    return x;
}