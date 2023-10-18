
// two possible operations:
// either count up a[X]++;
// or set all from a[0] to a[N] = max counter;
// i want to do it simple way by making 2 different functions, one for each

// order of operation
// 1. allocate for result structure, size of times N
// 2. Check first digit and go outside to right function
// 3. iterate the whole array and repeat second step.

// N = Number of arrays needed, A = Array, M = counter number

//EDIT 1: THIS DOESNT WORK IF MAX IS 0 BEFORE 1st count
// EDIT 2: IM dumb, max should not be pumped up if there is nothing that pumps it up in the array

//result is  88%, there is still some kind of timeout with large


struct Results {
  int * C;
  int L; // Length of the array
};

int *maxcount(int *res, int N, int max);

struct Results solution(int N, int A[], int M) {
    // Implement your solution here
    struct Results result;
    int *res;
    int x = 0;
    int max = 0;

    res = (int *)malloc(sizeof(int) * N);
    while (x < N)
    {
        res[x] = 0;
        x++;
    }
    x = 0;

    while (x < M + 1)
    {
        if (A[x] == N + 1)
        {
            res = maxcount(res, N, max);
        }
        else if (A[x] > 0 && A[x] < N + 1)
        {
            res[A[x] - 1]++;
            if (res[A[x] - 1] > max)
                max++;
        }
        x++;
    }
    result.C = res;
    result.L = N;
    return result;
}

int *maxcount(int *res, int N, int max)
{
    int x = 0;
    while (x < N + 1)
    {
        res[x] = max;
        x++;
    }
    return res;
}