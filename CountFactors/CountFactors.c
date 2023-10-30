// A positive integer D is a factor of a positive integer N if there exists an integer M such that N = D * M.
// 
// For example, 6 is a factor of 24, because M = 4 satisfies the above condition (24 = 6 * 4).
// 
// Write a function:
// 
// int solution(int N);
// 
// that, given a positive integer N, returns the number of its factors.
// 
// For example, given N = 24, the function should return 8, because 24 has 8 factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.

//this solution is easiest and O(N)

// int solution(int N)
// {
//     int i = 1;
//     int res = 0;
//     while(i <= N)
//     {
//         if(N % i == 0)
//         {
//             res++;
//         }
//         i++;
//     }
//     return res;
// }

// next try with efficiency 

// 92%, effiency still bugging. reaches 6s with MAXINT, why?
// i believe problem is that sqrtMAX_INT * sqrtMAX_INT goes overboard, but ill leave fixing for later, effiency is already O(sqrt(N))

int solution(int N)
{
    int i = 1;
    int res = 0;
    // as long as squareroot of N
    while(i * i < N)
    {
        // if mod is 0
        if(N % i == 0)
            // up by 2 because we found 2 divisors then (1x12 and 12x1 etc..)
            res = res + 2;
        i++;
    }
    // perfect sqrt check (6X6 or smth)
    if (i * i == N)
        res++;
    return res;
}