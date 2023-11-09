// really basic solution, 100%

// convert int to binary string one by one
// -> make first occurance of 1 starting point
// -> count every 0 after the start until the second occurance of 1
// -> update the max value if its lower than new current
// -> only update when there has already been start point, and its now at end point.

// small update: no need to use array since we go number by number, used variable of rem instead

int solution(int N) 
{
    int current = 0;
    int max = 0;
    int start = 0;
    int rem = 0;

    while (N > 0)
    {
        rem = N % 2;
//        printf("%d", rem);
        if (rem == 0 && start == 1)
        {
            current++;
        }
        else if (rem == 1)
        {
            if (start == 0)
            {
                start = 1;
            }
            else if (start == 1)
            {
                if (current > max)
                {
                    max = current;
                }
            }
            current = 0;
        }
        N = N / 2;
    }
    return max;
}