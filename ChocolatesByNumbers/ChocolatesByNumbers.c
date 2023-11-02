// Two positive integers N and M are given. Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N − 1.
// 
// You start to eat the chocolates. After eating a chocolate you leave only a wrapper.
// 
// You begin with eating chocolate number 0. Then you omit the next M − 1 chocolates or wrappers on the circle, and eat the following one.
// 
// More precisely, if you ate chocolate number X, then you will next eat the chocolate with number (X + M) modulo N (remainder of division).
// 
// You stop eating when you encounter an empty wrapper.
// 
// For example, given integers N = 10 and M = 4. You will eat the following chocolates: 0, 4, 8, 2, 6.
// 
// The goal is to count the number of chocolates that you will eat, following the above rules.
// 
// Write a function:
// 
// int solution(int N, int M);
// 
// that, given two positive integers N and M, returns the number of chocolates that you will eat.

// first thoughts: 
// make an bool array of eaten and non eaten chocos, size of N
// while u can (N + I % M) = eaten
// --> change bool value
// I = (N + I % M);

// second try:
// -> way too slow
// -->read the pdf about eucaledean method
// ---> better freshenup on binary sos

// answer was almost straight given in task pdf, took a while to understand why it works like this tho

// gives us greatest common divisor
int gcd(int a, int b)
{
    // printf("a: %d, b: %d \n", a, b);
    if (a == 0)
        return b;
    // if a != 0, we take mod, and do again
    // a = b % a & b = a
    return gcd(b % a, a);
}

int solution(int N, int M) 
{
    int res;

    // divide the number of itegers by greatest common divisor
    res = N / gcd(N, M);
    // printf ("res: %d\n", res);
    return res;
}