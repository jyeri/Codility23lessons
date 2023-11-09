// Notes to self: 
// so we need to find in the array path from 1 -> X
// store the smallest possible time window

// A = array
// K = time when its falling
// A[K] = position where its falling

// took too long to realise easiest solution:
// we iterate the array
// -> if there is first time leaf in path
// -> we increment value that keeps track is the path fully done
// -> when tracker is == X, means path is fully ready
// -> because i is the time, its always same as result
// if we dont occupy the full path by the end of loop, there is no path.

// only new problem was with allocating to bool array, but i guess ill just use stack.
#include <stdbool.h>
#include <string.h>

int solution(int X, int A[], int N)
{
    int i = 0;
    int position = 0;
    int occupied = 0;
    bool arr[X + 1];

    while (i <= X)
    {
        arr[i] = false;
        i++;
    }
    i = 0;
    while (i < N)
    {
        position = A[i];
        // first time inside the path
        if (position <= X && !arr[position])
        {
            arr[position] = true;
            occupied++;
        }
        // path is ready, result is index
        if (occupied == X)
        {
            return i;
        }
        i++;
    }
    return -1;

}