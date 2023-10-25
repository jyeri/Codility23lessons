// We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. 
// The J-th disc is drawn with its center at (J, 0) and radius A[J].
// 
// We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).
// 
// The figure below shows discs drawn for N = 6 and A as follows:
// 
//   A[0] = 1
//   A[1] = 5
//   A[2] = 2
//   A[3] = 1
//   A[4] = 4
//   A[5] = 0
// 
// 
// There are eleven (unordered) pairs of discs that intersect, namely:
// 
// discs 1 and 4 intersect, and both intersect with all the other discs;
// disc 2 also intersects with discs 0 and 3.

// first idea:
// iterate whole array A, and check how many overlaps there is, then move on to next index.. in this case something like this:
// if (x + A[x]) > (i - A[i]) && (x + A[x]) < (i + A[i]); counter++; i++;

// small change: discs complitely inside of other discs also counts :D


int solution(int A[], int N)
{
    int x = 0;
    int i = 0;
    int counter = 0;

    if (N < 2)
        return 0;

    while (x =< N)
    {
        i = x + 1;
        while (i =< N)
        {
            if ((x + A[x]) > (i - A[i]))
                counter++;
            i++;
        }
        x++;
    }
    return counter;
}