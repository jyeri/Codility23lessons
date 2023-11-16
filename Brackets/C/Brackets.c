// similar to school exam, first idea is tro try implement same solution
// we go tru the array and keep counter of each pair. if any of them ends up being anything else than 0, we exit


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

// IGNORE THE FIRST IDEA:

// int solution(char *S)
// {
//     int x1 = 0;
//     int x2 = 0;
//     int x3 = 0;
//     while (*S)
//     {
//         if (*S == '(')
//         {
//             x1++;
//         }
//         else if (*S == '{')
//         {
//             if (x1 != 0 || x2 != 0 )
//                 return 0;
//             x3++;
//         }
//         else if (*S == '[')
//         {
//             if (x1 != 0)
//                 return 0;
//             x2++;
//         }
//         else if (*S == ')')
//             x1--;
//         else if (*S == '}')
//         {
//             x3--;
//         }
//         else if (*S == ']')
//         {
//             x2--;
//         }
//         if (x1 < 0 || x2 < 0 || x3 < 0)
//             return 0;
//         *S++;      
//     }
//     if (x1 == 0 && x2 == 0 && x3 == 0)
//         return 1;
//     else
//         return 0;
// }
 // ({{({}[]{})}}[]{})