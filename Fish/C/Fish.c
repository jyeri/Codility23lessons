
// similar to brackets.
// start by allocating bit of stack memory, making again topstack of fishes going downstream, when directions changes, fish in topstack fight fishes until gets eaten/ direction is same
// small edit after push: there was extra incementation of x

int solution(int A[], int B[], int N)
{
    int stack[N];
    int top = 0;
    int x = 0;
    int cnt = 0;

    while (x < N)
    {
 //       printf("x: %d, A[x]: %d, B[x]: %d \n", x, A[x], B[x]);
        if (B[x] == 1)
        {
            //add downstreamers to stack
            stack[top++] = A[x];
        }
        else 
        {
            // eat the small fishies
            while (top && (stack[top-1] < A[x])) 
            {
                top--;
            }
            if (top == 0) 
            {
                // this guy was bigger than others so go to next and let this one pass
                cnt ++;
            }
        }
        x++;
    }
//    printf ("RESULT cnt: %d + top: %d!\n", cnt, top);
    return cnt + top;
}