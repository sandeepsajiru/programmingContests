#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

void uva11727()
{
    int t, a, b, c, ans, i=1;
    scanf("%d", &t);
    while(t--!=0)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a>=b && b>=c || c>=b && b>=a)
            ans = b;
        else if(b>=a && a>=c || c>=a && a>=b)
            ans = a;
        else
            ans= c;
        printf("Case %d: %d\n", i++, ans);
    }
}





