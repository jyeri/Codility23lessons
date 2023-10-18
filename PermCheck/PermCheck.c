// A non-empty array A consisting of N integers is given.
// 
// A permutation is a sequence containing each element from 1 to N once, 
// and only once.
// 
// For example, array A such that:
// 
//     A[0] = 4
//     A[1] = 1
//     A[2] = 3
//     A[3] = 2
// is a permutation, but array A such that:
// 
//     A[0] = 4
//     A[1] = 1
//     A[2] = 3
// is not a permutation, because value 2 is missing.
// 
// The goal is to check whether array A is a permutation.

// Notes to self: 
// goal is to find if array has numbers from 1 to N
// should be able to do without rereading the array
// return 1 if true, 0 if untrue

// we could check if doubles?
// if no duplicates array should always be size of N - 1 with highest number being N?

// in this case order of operatin is to loop thru array, save highest digit and check if duplicates?
//duplicate check is too slow like this but still works until timeout.
// added early return when highest number is bigger than array size. still too slow duplicate check


int duplicates(int A[], int N);

int solution(int A[], int N)
{
    if (duplicates(A, N) == 1)
        return 0;
    else 
        return 1;
}

int duplicates(int A[], int N)
{
    int i = 0;
    int j = 1;
    int max = 0;

    while (i < N)
    {
        if (max < A[i])
        {
            max = A[i];
            if (max > N)
            {
                return 1;
            }
        }
        j = i + 1;
        while (j < N)
        {
            if (A[i] == A[j])
            {
                return 1;
            }
            j++;
        }
        i++;
    }
    if (max == N)
        return 0;
    else
        return 1;
}
