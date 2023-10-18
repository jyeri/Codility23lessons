// Write a function:
// 
// int solution(int A, int B, int K); }
// 
// that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:
// 
// { i : A ≤ i ≤ B, i mod K = 0 }
// 
// For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.


// First thought is just iterate from A to B and check if modulo is 0, if yes increment the counter and return it when done.
// works, but time out when max int etc.

//int solution(int A, int B, int K)
//{
//    int res = 0;
//
//    while (A < B + 1)
//    {
//        if (A % K == 0)
//            res++;
//        A++;
//    }
//    return res;
//}

// second try is to cut down needed calculations in high digits:
// skip all the values that K is bigger than A?
// IF A % K == 0, then next divisible cant be lower than A + K?

int solution(int A, int B, int K)
{
    int res = 0;

    if (A < K)
        A = K;
    while (A < B + 1)
    {
        if (A % K == 0)
        {
            res++;
            A = A + A;
        }
        else
            A++;
    }
    return res;
}

//failed tests:
// [0, 2000000000, 1]
// A = 100, B=123M+, K=2
// A = 101, B = 123M+, K = 10K
// A = 0, B = MAXINT, K in {1,MAXINT}
// A, B, K in {1,MAXINT}

// okay some math genious tips
// so we need smallest and highest possible divisor (B / K and A / K) 

int solution(int A, int B, int K) 
{
    if(A == 0) 
    {
        return B/K + 1;
    } 
    else 
    {
        return B/K -(A - 1)/K;
    }
}

