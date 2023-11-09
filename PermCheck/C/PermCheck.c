// Notes to self: 
// goal is to find if array has numbers from 1 to N
// should be able to do without rereading the array
// return 1 if true, 0 if untrue

// we could check if doubles?
// if no duplicates array should always be size of N - 1 with highest number being N?

// in this case order of operatin is to loop thru array, save highest digit and check if duplicates?
//duplicate check is too slow like this but still works until timeout.
// added early return when highest number is bigger than array size. still too slow duplicate check

//REDONE:
// im working with assumption that valid string starts from 1
// like [1, 4, 2, 3] and not [2, 4, 3, 5]
int solution(int A[], int N) 
{
    int *arr;
    int i = 0;
    arr = (int *)calloc(N, sizeof(int));

    while(i < N) 
    {
        // check if its higher than N, if yes just exit with 0
        if(A[i] > N) 
        {
            return 0;
        }
        //increment that position on our array
        arr[A[i] - 1] ++;
        i++;
    }
    i = 0;
    while(i < N) 
    {
        // iterate our array and check if there is multiple occurances of same
        if(arr[i] > 1) 
        {
            return 0;
        }
        i++;
    }
    return 1;
}

    // if we wanted to allow strings like 2,3,4
    // we would need to:
    // establish starting point in second loop
    // use different counter than N
