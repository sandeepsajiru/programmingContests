#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;



void uva11547()
{
    int t, n;
    scanf("%d", &t);
    while(t--!=0)
    {
        scanf("%d", &n);
        int ans = (((n*567)/9+7492)*235)/47 - 498;
        if(ans<0)
            ans= -1*ans;
        printf("%d\n", (ans/10)%10);
    }
}


int main()
{
    uva11547();
    return 0;
}


