//A DNA sequence can be represented as a string consisting of the letters A, C, G and T, 
//which correspond to the types of successive nucleotides in the sequence. 
//Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. 
//You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?
//
//The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. 
//There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. 
//The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).


// General understanding: We compare S from P[x] to Q[x]; x++, and find smallest value "genome"
// A = 1
// C = 2
// G = 3
// T = 4

// S = seq
// P AND Q = indexes
// M = Length of arr (number of queries)

// first thought would we just to check S[P[x]] to S[Q[x]] and hold the lowest one found.
// problem with this is effiency, we would need to iterate everytime we get new query. does it matter?


#include <limits.h>

struct Results {
  int * A;
  int M; // Length of the array
};

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

struct Results solution(char *S, int P[], int Q[], int M)
{
    int *res;
    int low = 5;
    int x = 0;
    int start = 0;
    int howmany = 0;
    struct Results result;

    res = malloc(sizeof(int) * M + 1);
    
    start = P[x];
    howmany = Q[x] - P[x];

    while (x < M)
    {
        start = P[x];
        howmany = Q[x] - P[x];
        while (howmany > -1)
        {
            if (S[start + howmany] == 'A')
                S[start + howmany] = (int)1;
            else if (S[start + howmany] == 'C')
                S[start + howmany] = (int)2;
            else if (S[start + howmany] == 'G')
                S[start + howmany] = (int)3;
            else if (S[start + howmany] == 'T')
                S[start + howmany] = (int)4;
            howmany--;
        }
        howmany = Q[x] - P[x];
        while (howmany >= 0)
        {
            if (low > S[start + howmany])
            {
                low = (int)S[start + howmany];
            }
            howmany--;
        }
        res[x] = low;
        low = 5;
        x++;
    }
    result.A = res;
    result.M = M;

    return result;
}