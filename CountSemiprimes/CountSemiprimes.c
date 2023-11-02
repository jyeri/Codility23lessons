// A prime is a positive integer X that has exactly two distinct divisors: 1 and X. 
// The first few prime integers are 2, 3, 5, 7, 11 and 13.
// 
// A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. 
// The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.
// 
// You are given two non-empty arrays P and Q, each consisting of M integers. 
// These arrays represent queries about the number of semiprimes within specified ranges.
// 
// Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 ≤ P[K] ≤ Q[K] ≤ N.
// 
// For example, consider an integer N = 26 and arrays P, Q such that:
// 
//     P[0] = 1    Q[0] = 26
//     P[1] = 4    Q[1] = 10
//     P[2] = 16   Q[2] = 20
// The number of semiprimes within each of these ranges is as follows:
// 
// (1, 26) is 10,
// (4, 10) is 4,
// (16, 20) is 0.
// Assume that the following declarations are given:
// 
// struct Results {
//   int * A;
//   int M; // Length of the array
// };
// 
// Write a function:
// 
// struct Results solution(int N, int P[], int Q[], int M);
// 
// that, given an integer N and two non-empty arrays P and Q consisting of M integers, 
// returns an array consisting of M elements specifying the consecutive answers to all the queries.


// first thoughts:
// make helper function to check if number is semi prime
// -> add it into temporary array in right index
//      -> gives us efficient checking method for every counted semiprime?
//      -> would cut down the cost of counting same primes again?
//      -> in the end we gather the result arrays from this temporary array with simple bool check?

// 2nd try:
// -> utilize prime table like last exercise
// -> make the array holding until X values instead of exact value for easy answear extraction
// -> check stack overflow what in bugging in time complexity, since result is correct already

// Variable notes:
// N = Max number
// M = How many in each array
// P = *int where
// Q = *int to

//helper function to check if number actually is semiprime

#include <string.h>

// similar approach than to last one.

struct Results solution(int N, int P[], int Q[], int M) 
{
    struct Results result;

    int *divisors;
    int *counter;
    int i;
    int k;
    divisors = (int *)malloc(sizeof(int)*(N+1));
    counter = (int *)malloc(sizeof(int)*(N+1));
    result.A = (int *)malloc(sizeof(int)*M);
    memset(result.A, 0, sizeof(int)*M);
    memset(divisors, 0, sizeof(int)*(N+1));
    memset(counter, 0, sizeof(int)*(N+1));
    
    i = 2;
    // we get divisors in range of 2 -> sqrt(N)
    while (i*i <= N) 
    {
        if (divisors[i] == 0) 
        {
            // we can always increment by i * i
            k = i * i;
            // printf("\nDivisors for multiplies of %d (not yet done):\n", i);
            while (k <= N) 
            {
                if (divisors[k] == 0)
                {
                    // printf("divisors[%d] is %d \n", k, i);
                    divisors[k] = i;
                }
                k += i;
            }
        }
        i++;
    }
    // printf("\n Next loop: \n\n");
    i = 1;

    // calculate how many counts there is for every number in ascending (add previous)
    while (i <= N) 
    {
        // printf("divisors[%d] is %d \n", i, divisors[i]);
        // if there was divisors up by one (unless not semi)
        if (divisors[i] != 0 && divisors[i / divisors[i]] == 0)
        {
            counter[i] = counter[i-1] + 1;
            // printf("1: counter[%d] is %d \n", i, counter[i-1] + 1);
        }
        else
        {
            counter[i] = counter[i-1];
            // printf("2: counter[%d] is %d \n", i, counter[i-1]);
        }
        i++;
    }
    // printf("\n Next loop: \n\n");
    i = 0;
    // iterate whole array pair and save to result struct
    while (i < M) 
    {
        // left is counter at end point Q[i] - start point P[i]
        result.A[i] = counter[Q[i]] - counter[P[i] - 1];
        // printf("res[%d] is %d - %d \n", i, counter[Q[i]], counter[P[i] - 1]);
        i++;
    }
    
    result.M = M;
    return result;
}


// easy solution as proof of concept-> without making the temp array and adding straight to result array
// worked and got alrady 66% -> now we implement the checking array

//helper function to check if number actually is semiprime
//  int check_semi(int num)
//  {
//      int cnt = 0;
//      int i = 2;
//   
//      // loop until find more than u primes or i > sqrt(Num)
//      while (cnt < 2 && i * i <= num)
//      {
//          while (num % i == 0)
//          {
//              num /= i;
//              ++cnt;
//          }
//          i++;
//      }
//      // If number is greater than 1, add it to
//      // the count variable as it indicates the
//      // number remain is prime number
//      if (num > 1)
//          ++cnt;
//   
//      // return cnt, if its 2 we all gucci
//      return cnt;
//  }
//  
//  struct Results solution(int N, int P[], int Q[], int M)
//  {
//  
//      struct Results res;
//      int i = 0;
//      int j = 0;
//      int k = 0;
//  
//      res.A = (int *)calloc(M * sizeof(int), sizeof(int));
//      res.M = M;
//  
//  // iterate given arrays
//      while(k < M)
//      {
//          j = Q[k] - P[k];
//          while (j >= 0)
//          {
//  //            printf("%d under check. \n", P[i] + j);
//              if (check_semi(P[i] + j) == 2)
//              {
//  //                printf("%d is prime. \n", P[i] + j);
//                  res.A[k] += 1;
//              }
//              j--;
//          }
//  //        printf("\n NEXT INDEX \n");
//          i++;
//          k++;
//      }
//  
//      return res;
//  }