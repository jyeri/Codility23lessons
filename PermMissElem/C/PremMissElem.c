

// My basic idea is simple, its not possibly fastest (but gave 100%)
// Add every number in A string to Miss variable
// then add every number from 1 to N + 1 to another ALL variable
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