//  An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.
//  
//  Your goal is to find that missing element.
//  
//  Write a function:
//  
//  int solution(int A[], int N);
//  
//  that, given an array A, returns the value of the missing element.
//  
//  For example, given array A such that:
//  
//    A[0] = 2
//    A[1] = 3
//    A[2] = 1
//    A[3] = 5
//  the function should return 4, as it is the missing element.
//  
//  Write an efficient algorithm for the following assumptions:
//  
//  N is an integer within the range [0..100,000];
//  the elements of A are all distinct;
//  each element of array A is an integer within the range [1..(N + 1)].

//My basic idea is simple, its not possibly fastest (but gave 100%)
//Add every number in A string to Miss variable
//then add every number from 1 to N + 1 to another ALL variable
// result is ALL - MISS since every number was numbers next to it 
// if the missing number was 0 it was already handled by making default value for res 0

int solution(int A[], int N) {
    // Implement your solution here
    int all = 0;
    int miss = 0;
    int res = 0;
    int i = 0;

    while (N > i)
    {
        miss += A[i];
        i++;
    }
    i = 1;
    while (N + 2 > i)
    {
        all += i;
        i++;
    }
    res = all - miss;
    return res;

}