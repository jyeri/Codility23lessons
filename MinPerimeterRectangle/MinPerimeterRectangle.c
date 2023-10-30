// An integer N is given, representing the area of some rectangle.
// 
// The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).
// 
// The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.
// 
// For example, given integer N = 30, rectangles of area 30 are:
// 
// (1, 30), with a perimeter of 62,
// (2, 15), with a perimeter of 34,
// (3, 10), with a perimeter of 26,
// (5, 6), with a perimeter of 22.
// Write a function:
// 
// int solution(int N);
// 
// that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.

// 70%, small problems in examples seen belove
// -> 100% problem was fixed with counting also x * x
// -> also hardcoded of area of 1

#include <limits.h>

int solution(int N)
{
    int i;
    int x;
    int tmpres = INT_MAX;
    int res = INT_MAX;

    i = 1;
    x = N;
    if (N == 1)
        res = 4;
    while(i <= x)
    {
//        printf("VALUES IN ROUND %d:\n", i);
        if (i * x == N)
        {
            tmpres = (2 * (x + i));
        }
        if (tmpres < res)
            res = tmpres;
//        printf("i: %d, x: %d, res: %d \n\n", i, x, res);
        i++;
        x = N / i;
    }
    return res;
}

//1 = 4 works
//36 = 24 works
//48 = 28 works
//101 = 204 works
//1234 = 1238 works
//4564320 = 8552 works
//14486451 = 30972904 wrong res: 1379704
//100,000,000 = 40000 works
//982,451,653 = 1964903308 works
//1,000,000,000 = 126500 works