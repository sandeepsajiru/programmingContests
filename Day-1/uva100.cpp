#include <iostream>
#include <cstdio>

using namespace std;

int getCL(int i)
{
    int cl = 0;
    while(true)
    {
        cl++;
        if(i==1)
            break;

        if(i%2==0)
            i = i/2;
        else
            i = 3*i+1;
    }
    return cl;
}

void uva100()
{
    int i, j, k;
    int ti, tj;
    int maxCL, cl;
    while(scanf("%d %d", &i, &j)==2)
    {

        ti = i;
        tj = j;

        if(i>j)
        {
            i = tj;
            j = ti;
        }

        maxCL = 0;

        for(k=i;k<=j;k++)
        {
            cl = getCL(k);
            if(maxCL < cl)
                maxCL = cl;
        }
        printf("%d %d %d\n", ti, tj, maxCL);
    }
}
