#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;



void uva11150()
{
    int n;
    while(scanf("%d", &n)==1)
    {
        int ans = n;

        while(n>2)
        {
            ans += n/3;
            n = n%3 + n/3;
        }

        if(n==2)
            ans++;

        printf("%d\n", ans);
    }
}







