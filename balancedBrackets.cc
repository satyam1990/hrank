/********************************************************************
 A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

 Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) 
 occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. 
 There are three types of matched pairs of brackets: [], {}, and ().

 A matching pair of brackets is not balanced if the set of brackets it encloses are not matched.
 For example, {[(])} is not balanced because the contents in between { and } are not balanced.
 The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of
 parentheses encloses a single, unbalanced closing square bracket, ].

 By this logic, we say a sequence of brackets is considered to be balanced if the 
 following conditions are met:

 It contains no unmatched brackets.
 The subset of brackets enclosed within the confines of a matched pair of brackets
 is also a matched pair of brackets.

 Given n strings of brackets, determine whether each sequence of brackets is balanced. 
 If a string is balanced, print YES on a new line; otherwise, print NO on a new line.

 Input Format

 The first line contains a single integer,n , denoting the number of strings. 
 Each line i of the n subsequent lines consists of a single string, s, denoting a sequence of brackets.

 Output Format

 For each string, print whether or not the string of brackets is balanced on a new line. If the brackets are balanced, print YES; otherwise, print NO.

 Sample Input
 4
 {[()]}
 {[(])}
 {{[[(())]]}}
 [](){()}

 Sample Output
 YES
 NO
 YES
 YES

********************************************************************/

#include <iostream>

using namespace std;

bool is_balanced(string expression) 
{
    int length = expression.length();
    char stack[length] = {0};
    int j = 0;

    // validate length
    if (length % 2 != 0)
        return false;

    for (int i = 0; i < length; i++, j++)
    {
        stack[j] = expression[i];
        
        if (j > 0)
        {
            // found one balanced pair remove from stack
            if (stack[j] - 1  == stack[j - 1]
                || stack[j] - 2 == stack[j - 1])
            {
                j -= 2;
            }
        }
    }
    
    if (j == 0)
        return true;

    return false;
}

int main()
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

