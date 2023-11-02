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

struct Results solution(int N, int P[], int Q[], int M)
{

}