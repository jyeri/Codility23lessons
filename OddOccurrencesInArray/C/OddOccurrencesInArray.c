// didnt come up to this solution without bit of help, but notes for myself:
// using the bitwise operator of XOR (^)
// shift the bits with every number of array once
// everytime same number occurs second time the bits are sifted back
// so result should be only number which bits didnt get sifted back to 0.
// now same with python

int solution(int A[], int N) {
    // Implement your solution here
    int ret = 0;
    int i = 0;
    while (i < N)
    {
        ret = ret ^ A[i];
        i++;
    }
    return ret;
}