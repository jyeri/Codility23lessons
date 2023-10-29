// An array A consisting of N integers is given. It contains daily prices of a stock share for a period of N consecutive days. 
// If a single share was bought on day P and sold on day Q, where 0 ≤ P ≤ Q < N, 
// then the profit of such transaction is equal to A[Q] − A[P], provided that A[Q] ≥ A[P]. 
// Otherwise, the transaction brings loss of A[P] − A[Q].
// 
// For example, consider the following array A consisting of six elements such that:
// 
//   A[0] = 23171
//   A[1] = 21011
//   A[2] = 21123
//   A[3] = 21366
//   A[4] = 21013
//   A[5] = 21367
// If a share was bought on day 0 and sold on day 2, a loss of 2048 would occur because A[2] − A[0] = 21123 − 23171 = −2048.
// If a share was bought on day 4 and sold on day 5, a profit of 354 would occur because A[5] − A[4] = 21367 − 21013 = 354. 
// Maximum possible profit was 356. It would occur if a share was bought on day 1 and sold on day 5.
// 
// Write a function,
// 
// int solution(int A[], int N);
// 
// that, given an array A consisting of N integers containing daily prices of a stock share for a period of N consecutive days, 
// returns the maximum possible profit from one transaction during this period. 
// The function should return 0 if it was impossible to gain any profit.

// first idea is just to iterate and remember high && low -> problem1: if high price is before low buy price, problem2: idk
// possible solution: save first low and first high. before erasing them always compare it to upcoming values.

// so what were looking for is start date-> maximum profit
// we can start declaring that its first day in beginning and "make a purchase"
// iterate the array until its either lower point than saved one
//      -> save the new lowpoint
// or until its new max selling point
//      -> save new maxpoint
// we save the profit and compare it to last saved one
//      -> if its higher maxprofit = profit
// return maxprofit

int solution(int A[], int N) 
{
    int maxprofit = 0;
    int i = 0;
    int profit = 0;
    int min = A[i];
    int max = A[i];

    // iterate array
    while (i < N)
    {
        // save new lowpoint and reset pointers
        if (min > A[i])
        {
            min = A[i];
            max = A[i];
        }
        // save new highpoint
        else if (max < A[i])
            max = A[i];
        // calculate current profit
        profit = max - min;
        // save possible new maxprofit
        if (profit > maxprofit)
            maxprofit = profit;
        i++;
    }
    return maxprofit;
}
