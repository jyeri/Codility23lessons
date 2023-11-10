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