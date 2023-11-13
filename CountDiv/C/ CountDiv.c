// First thought is just iterate from A to B and check if modulo is 0, if yes increment the counter and return it when done.
// works, but time out when max int etc.

// second try is to cut down needed calculations in high digits:
// skip all the values that K is bigger than A?
// IF A % K == 0, then next divisible cant be lower than A + K?

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

