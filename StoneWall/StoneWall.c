// You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; 
// however, it should have different heights in different places. The height of the wall is specified by an array H of N positive integers. 
// H[I] is the height of the wall from I to I+1 meters to the right of its left end. 
// In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.
// 
// The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). 
// Your task is to compute the minimum number of blocks needed to build the wall.

// First idea is just forget everything i read, and thinking that everytime height changes, i need a new block, yes?
// no...

// ok so i had look up from pdf little bit of help.
// Basic idea:
// go array from left to right->
// add starting point in stack & add one block into contruction->
// incement to next point in array
// check if were on down hill-> delete from stack everything thats higher (can be made from same block)
// if its not equal, just skip.
// if its lower or there is nothing anymore on stack -> make new cuboid and add this point to stack
// increment until N

int solution(int H[], int N) 
{
    int i = 0;
    int cuboids = 0;
    int stack[100000];
    int top = 0;
    int skip = 0;

    while (i < N)
    {
        // there is higher point in top of stack
        while (top > 0 && stack[top - 1] > H[i])
            top--;
        // top of stack is equal height (can be done with same block so skip)
        if  (top > 0 && stack[top - 1] == H[i])
            skip++;
        // other means either stacktop is now 0, or point is lower than stack so we need to make new cuboid and add this point to stack
        else
        {
            cuboids++;
            stack[top] = H[i];
            top++;
        }
        i++;
    }
    return cuboids;
}
