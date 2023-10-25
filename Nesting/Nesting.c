//tried to overthink once again
//solution is simply to iterate the array, save every opening, if there the closing match or exceeds return 0.


int solution(char *S) 
{
    int     i = 0;
    int     top = 0;
    
    while (S[i])
    {
//      printf("current: %c\n", S[i]);
        if (S[i] == '(')
        {
 //         printf("+\n");
            top++;
            if (top > 500000)
                return 0;
        }
        else if (S[i] == ')')
        {
 //         printf("-\n");
            top--;
            if (top < 0)
                return 0;
        }
        i++;
    }
    return (!top);
}