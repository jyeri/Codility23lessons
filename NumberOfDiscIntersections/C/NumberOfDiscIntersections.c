// first idea:
// iterate whole array A, and check how many overlaps there is, then move on to next index.. in this case something like this:
// if (x + A[x]) > (i - A[i]) && (x + A[x]) < (i + A[i]); counter++; i++;

// small change: discs complitely inside of other discs also counts :D

// next set of changes got me to 75%, problems still to fix are overflow with 2 values (store in lonf instead of int?) and effiency in big arrays (time outs with 10000 > N)

// now got me 100% with basically mimicing stack overflow. I understand the idea now bit better, couldn't probably redo tho.

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    int C[N];
    int a = 0;
    int S = 0;
    int t = 0;
    int i = 0;

    // Mark left and middle of disks
    while (i < N) 
    {
        // mark our new array to -1
        C[i] = -1;
        a = A[i];
//        printf("Current A[%d]: %d -> ", i, A[i]);
        // if A[i] is bigger than index??
        if (a >= i) 
        {
            // we increment C[0] ?
            C[0]++;
//            printf("C[0] incremented to %d \n", C[0]);
        }
        else 
        {
            // else we increment C[index - A[i]]
            C[i - a]++;
//            printf("C[%d] incremented to %d \n", i - a, C[i - a]);
        }
        // move to next disc
        i++;
    }

    i = 0;
    // count of left sides of disc in index
    while (i < N) 
    {
        // t is holding values of our new array from left to right (if not modified there is -1)
//        printf ("C[%d] = %d -> ", i, C[i]);
        t += C[i];
        C[i] = t;
//        printf(" %d \n", C[i]);
        i++;
    }

    i = 0;
    // Count pairs
    while (i < N) 
    {
        a = A[i];
        // If Condition is true ? then value X : otherwise value Y
        // so if A[i] < N - 1, then S += A[i]
        // else S += N - i - 1
        S += ((a < N - i) ? a : N - i - 1);
//        printf("A[%d]: %d, S = %d  ->  ", i, a, S);
        if (i != N - 1) 
        {
            // if A[i] < N - i, then S += C[i + a]
            // else S += C[N - 1]
            S += C[((a < N - i) ? i + a : N - 1)];
//            printf("S = %d \n", S);

        }
        if (S>10000000) 
            return -1;
        i++;
    }
    return S;
}