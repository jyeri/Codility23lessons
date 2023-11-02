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

// Variable notes:
// N = Max number
// M = How many in each array
// P = *int where
// Q = *int to

struct Results solution(int N, int P[], int Q[], int M)
{

// -> allocate array of int from 0 to N?
//      -> 0 = not checked, 1 = checked, not semiprime, 2 = semiprime?
    int *semiprimes;
    struct Results res;
    int i = 0;
    int j = 0;
    int k = 0;

    semiprimes = (int *)calloc(N * sizeof(int));
    res.A = (int *)calloc(M * sizeof(int));
    res.L = M;

// iterate given arrays
    while(k < M)
    {
        j = Q[k] - P[k];
        while (j > 0)
        {
            if (semiprimes[P[i]] == 0)
            {
                if (check_semi(P[i]) == 2)
                    semiprimes[P[i]] = 2;
                else
                    semiprimes[P[i]] = 1;
            }
            i++;
            j--;
        }
        i = 0;
        k++;
    }
// iterate once more to add checked into res A
    i = 0;
    while(i < M)
    {
    }
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