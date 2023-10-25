// A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
// 
// S is empty;
// S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
// S has the form "VW" where V and W are properly nested strings.
// For example, the string "{[()()]}" is properly nested but "([)()]" is not.
// 
// Write a function:
// 
// int solution(char *S);
// 
// that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.
// 
// For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.
// 
// Write an efficient algorithm for the following assumptions:
// 
// N is an integer within the range [0..200,000];
// string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'.

// similar to school exam, first idea is tro try implement same solution
// we go tru the array and keep counter of each pair. if any of them ends up being anything else than 0, we exit


// IGNORE:

int solution(char *S)
{
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    while (*S)
    {
        if (*S == '(')
        {
            x1++;
        }
        else if (*S == '{')
        {
            if (x1 != 0 || x2 != 0 )
                return 0;
            x3++;
        }
        else if (*S == '[')
        {
            if (x1 != 0)
                return 0;
            x2++;
        }
        else if (*S == ')')
            x1--;
        else if (*S == '}')
        {
            x3--;
        }
        else if (*S == ']')
        {
            x2--;
        }
        if (x1 < 0 || x2 < 0 || x3 < 0)
            return 0;
        *S++;      
    }
    if (x1 == 0 && x2 == 0 && x3 == 0)
        return 1;
    else
        return 0;
}
 // ({{({}[]{})}}[]{})

// new try: i need to keep hold on whats top of the stack so everything that has equal ending and closing does not pass
// took a while to remember how to do the check.
// basic idea: save every opening bracket in array, when closing bracket comes -> check if previously opened is same. else we have problem

int match(char a, char b)
{
    // just helper to check if matching bracket
	return ((a == '[' && b == ']') || (a == '{' && b == '}') \
				|| (a == '(' && b == ')'));
}

int solution(char *S)
{
	int		i;
	int		top;
	int		stack[200000];

	i = 0;
	top = 0;
    // iterate string
	while (S[i])
	{
        // save openings on stack[top]
		if (S[i] == '(' || S[i] == '{' || S[i] == '[')
			stack[++top] = S[i];
        // check if closing matches prev opening
		if (S[i] == ')' || S[i] == '}' || S[i] == ']')
			if (!match(stack[top--], S[i]))
				return (0);
                // if not ret 0
        // increment
		i += 1;
	}
    // return top what should be 0
	return (!top);
}