
// An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.
// 
// For example, consider array A such that
// 
//  A[0] = 3    A[1] = 4    A[2] =  3
//  A[3] = 2    A[4] = 3    A[5] = -1
//  A[6] = 3    A[7] = 3
// The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.
// 
// Write a function
// 
// int solution(int A[], int N);
// 
// that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. 
// The function should return −1 if array A does not have a dominator.

// using majority vote problems solution
// -> iterate array
// -> if
//      1. current pointer, increment the counter
//      2. counter is 0, put pointer in current index and set counter to one
//      3. if counter > 0, means that its part of other group, so we decrement the counter
// -> after we should have the largest nominator in array
// -> iterate the array and check how many of them are there. save the last occurance for result
// -> check if there is more than half of N.
// -> return accordingly

int solution(int A[], int N) 
{
    int B[N];
    int counter = 0;
    int i = 0;
    int ret = 0;

    while(i < N)
    {
        if(B[N] == A[i])
            counter++;
        else if (counter == 0)
        {
            B[N] = A[i];
            counter = 1;
        }
        else 
        {
            counter--;
        }
        i++;
    }
    i = 0;
    counter = 0;
    while(i < N)
    {
        if (A[i] == B[N])
        {
            counter++;
            ret = i;
        }
        i++;
    }
    if (N / 2 < counter)
        return ret;
    else
        return -1;

}