// General understanding: We compare S from P[x] to Q[x]; x++, and find smallest value "genome"
// A = 1
// C = 2
// G = 3
// T = 4

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Results solution(char *S, int P[], int Q[], int M)
{
    unsigned length;
    length = strlen(S);

    int A[length];
    int C[length];
    int G[length];
    int T[length];

    struct Results result = {calloc(M, sizeof(int)), M};

    int i = 0;

    while (i < length) 
    {
        if (i == 0)
            A[i] = C[i] = G[i] = T[i] = 0;
        else 
        {
            A[i] = A[i - 1];
            C[i] = C[i - 1];
            G[i] = G[i - 1];
            T[i] = T[i - 1];
        }
        switch (S[i]) 
        {
            case 'A':
                ++A[i];
                break;
            case 'C':
                ++C[i];
                break;
            case 'G':
                ++G[i];
                break;
            case 'T':
                ++T[i];
                break;
        }
        i++;
    }

    i = 0;

    // this is so not my doings, but ill try to explain what i got from this:
    // we compare which of the results changes in give time period from our array
    while (i < M) 
    {
        if (A[Q[i]] - (P[i] > 0 ? A[P[i] - 1] : 0) > 0)
            result.A[i] = 1;
        else if (C[Q[i]] - (P[i] > 0 ? C[P[i] - 1] : 0) > 0)
            result.A[i] = 2;
        else if (G[Q[i]] - (P[i] > 0 ? G[P[i] - 1] : 0) > 0)
            result.A[i] = 3;
        else
            result.A[i] = 4;
        i++;
    }
    return result;
}