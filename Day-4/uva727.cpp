#include <cstdio>
#include <stack>
#include <cstring>
#include <cctype>

using namespace std;

void uva727();

char ans[200];

bool isOperator(char c)
{
    return (c=='*' || c=='/' || c=='-' || c=='+');
}

int getPrecedence(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c==')' || c=='(')
        return 3;
    return 0;
}

void uva727()
{
    char c;
    char t;
    bool isSecondInput = false;
    stack<int> stk;
    char line[10];
    int tc;
    scanf("%d\n", &tc);
    while(tc--)
    {
        a = 0;
        while(gets(line))
        {
            if(strlen(line)==0)
            {
                if(isSecondInput)
                {
                    break;
                }
                continue;
            }
            else
                isSecondInput = true;


            c = line[0];

            if(isdigit(c)) // DIGIT
                ans[a++] = c;
            else if(isOperator(c)) // OPERATOR
            {
                // IF HIGH PRI OPERATORS ARE IN STACK - POP AND PRINT THEM FIRST
                while(!stk.empty())
                {
                    t = stk.top();
                    if(isOperator(t) && getPrecedence(t)>=getPrecedence(c))
                    {
                        printf("%c", t);
                        stk.pop();
                    }
                    else
                        break;
                }
                stk.push(c);
            }
            else if(c=='(')
            {
                stk.push(c);
            }
            else if(c==')')
            {
                while(!stk.empty())
                {
                    t = stk.top();
                    if(t!='(')
                    {
                        printf("%c", t);
                        stk.pop();
                    }
                    else
                        break;
                }
            }
        }

        while(!stk.empty())
        {
            if(stk.top()!='(')
                printf("%c", stk.top());
            stk.pop();
        }
        printf("\n");
    }
}
int main()
{
    uva727();
    return 0;
}
