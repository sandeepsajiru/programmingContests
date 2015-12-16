#include <cstdio>
#include <stack>

using namespace std;

char line[200];

bool isMatching(char line[])
{
    int i=0;
    stack<int> stk;

    char c, t;
    while(line[i]!='\0')
    {
        c = line[i];
        if(c=='[' || c=='(')
            stk.push(c);
        else if(c==')')
        {
            if(stk.empty())
                return false;
            t = stk.top();
            if(t!='(')
                return false;
            stk.pop();
        }
        else if(c==']')
        {
            if(stk.empty())
                return false;
            t = stk.top();
            if(t!='[')
                return false;
            stk.pop();
        }

        i++;
    }
    return stk.empty();
}
void uva673()
{
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        gets(line);
        if(isMatching(line))
            printf("Yes\n");
        else
            printf("No\n");
    }
}
