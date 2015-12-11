#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int getSonarCount(int n, int m)
{
    int i=2, j=2;
    int count = 1;
    while(1)
    {
        if(j+3<=m-1)
            j = j+3;
        else if(i+3<=n-1){
            i = i+3;
            j = 2;
        }
        else
        {
            break;
        }
        //printf("%d %d\n", i, j);
        count++;
    }
    return count;
}
void uva11044()
{
    int t, n, m;
    scanf("%d", &t);
    while(t!=0){
        scanf("%d %d", &n, &m);
        printf("%d\n", getSonarCount(n, m));
        t--;
    }
}
