// A prime is a positive integer X that has exactly two distinct divisors: 1 and X. 
// The first few prime integers are 2, 3, 5, 7, 11 and 13.
// 
// A prime D is called a prime divisor of a positive integer P if there exists a positive integer K such that D * K = P. 
// For example, 2 and 5 are prime divisors of 20.
// 
// You are given two positive integers N and M. 
// The goal is to check whether the sets of prime divisors of integers N and M are exactly the same.
// 
// For example, given:
// 
// N = 15 and M = 75, the prime divisors are the same: {3, 5};
// N = 10 and M = 30, the prime divisors aren't the same: {2, 5} is not equal to {2, 3, 5};
// N = 9 and M = 5, the prime divisors aren't the same: {3} is not equal to {5}.
// Write a function:
// 
// int solution(int A[], int B[], int Z);
// 
// that, given two non-empty arrays A and B of Z integers, 
// returns the number of positions K for which the prime divisors of A[K] and B[K] are exactly the same.

// A = 1st array
// B = 2nd array
// Z = number of integers in array


// use gcd to find common divisor?
// continue using it to a/2 and b/2?

// reread the pdf and went with clearest approach i could
//  -> take A[i] & B[i]
//  -> take gcd
//  -> take k = gcd(gcdvalue, a)
//  -> as long as gcd of a / k ends up in 1
//  -> same to be and ends up in 1
//      -> these have same prime divisors
//  -> else they wont both end up to 1

int gcd(int a, int b)
{
    // printf("a: %d, b: %d \n", a, b);
    if (a == 0)
        return b;
    // if a != 0, we take mod, and do again
    // a = b % a & b = a
    return gcd(b % a, a);
}


int solution(int A[], int B[], int Z)
{
    int i = 0;
    int res = 0;
    int k = 0;
    int gcdval = 0;
    int a = 0;
    int b = 0;

    while(i <= Z)
    {
        // store modifiable a, b, and gcd values
        a = A[i];
        b = B[i];
        gcdval = gcd(a, b);
        k = gcd(gcdval, a);
//        printf("A[i]: %d, B[i]: %d, gcdval: %d k = %d \n", a, b, gcdval, k);
        // as long us the result comes as 1 to a
        while(k > 1)
        {
//            printf("k: %d, a: %d \n", k, a);
            a = a / k;
            k = gcd(gcdval, a);
        }
        k = gcd(gcdval, b);
        // as long us the result comes as 1 (same to b)
        while(k > 1)
        {
            //printf("k: %d, b: %d \n", k, b);
            b = b / k;
            k = gcd(gcdval, b);
        }
        // if both are exactly 1, they should have same prime divisors
        if (a == 1 && b == 1)
            res += 1;
        i++;
    }
    return res;
}