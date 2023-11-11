// First thoughts:
// if we have to know specifig car pairs delete this, but if just number of passing ones: we could should just count number of cars going E and number of cars going West
// then its simply E(X) * W + E(X) * W(X->)

// second idea: everytime we find same direction car, we pump up icrementation by one, and keep adding the pump number till the end.
// 90%, problem with two cars. (this is wrong in the test since it should be 1 when they pass any either 0,1 or 1,0 and 0 when they go same direction) can fix if we just start
// the count in first car heading EAST, instead of counting first car no matter direction.

int solution(int A[], int N)
{
    int x = 0;
    int westheads = 0;
    int total = 0;

    while (x < N)
    {
        //same direction
        if (A[x] == 0)
            westheads++;
        //other direction
        else
            total = total + westheads;
        if (total > 1000000000)
            return -1;
        x++;
    }

    return total;
}
