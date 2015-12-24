#include <stdio.h>
#include <stdlib.h>

int getChangeCoinCountBacktrackingInternal(int d[], int n, int m, int i)
{
    if(m==0)return 0;
    if(m<0)return n+1;

    int withI=n+1, withOutI=n+1;

    withI = 1+getChangeCoinCountBacktrackingInternal(d, n, m-d[i], i);
    if(i+1<n)
        withOutI = getChangeCoinCountBacktrackingInternal(d, n, m, i+1);

    return withI<withOutI?withI:withOutI;
}
int getChangeCoinCountBacktracking(int d[], int n, int m)
{
    return getChangeCoinCountBacktrackingInternal(d, n, m, 0);
}
int getChangeCoinCountBacktrackingTest()
{
    int d[] = {1, 5, 7, 9};
    int n = sizeof(d)/sizeof(int);
    int m =10;
    printf("%d", getChangeCoinCountBacktracking(d, n, m));
    return 0;
}
