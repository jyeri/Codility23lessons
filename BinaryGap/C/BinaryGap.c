// really basic solution, 100%

// convert int to binary string one by one
// -> make first occurance of 1 starting point
// -> count every 0 after the start until the second occurance of 1
// -> update the max value if its lower than new current
// -> only update when there has already been start point, and its now at end point.

int solution(int N) 
{
    int arr[32];
    int i = 0;
    int current = 0;
    int max = 0;
    int start = 0;

    while (N > 0)
    {
        arr[i] = N % 2;
//        printf("%d", arr[i]);
        if (arr[i] == 0 && start == 1)
        {
            current++;
        }
        else if (arr[i] == 1)
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