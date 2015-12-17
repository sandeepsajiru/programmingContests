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
    return 0;
}

void uva727()
{
    stack<int> stk;
    char ans[50];
    int a;
    int tc;
    char c, t;
    bool isFirstBlankLine  = true;
    char line[10];
    scanf("%d\n", &tc);
    while(tc--)
    {
        a = 0;
        while(gets(line))
        {
            // Ignore First Blank Line after test cases
            if(isFirstBlankLine)
            {
                isFirstBlankLine = false;
                continue;
            }
            // Empty Line Indicates End Of Test Data
            if(strlen(line)==0)
                break;

            c = line[0];
            if(isdigit(c)) // DIGITS ARE PRINTED DIRECTLY
                ans[a++]=c;
            else if(c=='(') // PUSH EXPRESSION BEGINNING
            {
                stk.push(c);
            }
            else if(c==')')
            {
                // Pop and print till ( is found
                while(!stk.empty())
                {
                    t = stk.top();
                    stk.pop();
                    if(t=='(')
                        break;
                    ans[a++]=t;
                }
            }
            else if(isOperator(c))
            {
                if(stk.empty())
                    stk.push(c);
                else
                {
                    t = stk.top();
                    if(getPrecedence(t) < getPrecedence(c))
                        stk.push(c);
                    else
                    {
                        while(getPrecedence(t)>= getPrecedence(c))
                        {
                            ans[a++]=t;
                            if(stk.empty())
                                break;
                            stk.pop();
                            t = stk.top();
                            if(t=='(')
                                break;
                        }
                        stk.push(c);
                    }
                }
            }

        }
        while(!stk.empty())
        {
            t = stk.top();
            ans[a++]=t;
            stk.pop();
        }
        ans[a]='\0';
        printf("%s\n", ans);
    }
}

