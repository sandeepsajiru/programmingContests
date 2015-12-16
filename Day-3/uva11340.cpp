#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;
#define CHARS_COUNT 280

int costs[CHARS_COUNT];
void setCostZeroes()
{
    memset(costs, 0, sizeof costs);
}

unsigned long getLineCost(char line[])
{
    int j;
    unsigned long lc=0;
    for(j=0; line[j]!='\0'; j++)
    {
        if(line[j]<0 || line[j]>127)
        {
            //printf("IGNORING** %c\n", line[j]);
            continue;
        }
        if(isprint(line[j]) && !isspace(line[j]))
        {
            lc += costs[line[j]];
        }
    }
    return lc;
}

void uva11340()
{
    int t, K, i, lc;
    char line[10005];
    scanf("%d\n", &t);
    char c;
    int ccost;
    while(t-->0)
    {
        scanf("%d\n", &K);

        for(i=1; i<=K; i++)
        {
            //gets(line);
            scanf("%c %d\n", &c, &ccost);
            if(!isspace(c) && isprint(c))
                costs[c] = ccost;
            //printf("'%c' %d\n", c, ccost);
        }

        scanf("%d\n", &lc);
        //printf("LC: %d\n", lc);
        double totalCost=0;
        for(i=1; i<=lc; i++)
        {
            gets(line);
            totalCost += getLineCost(line);
        }

        printf("%.2lf$\n", totalCost/100);
        setCostZeroes();
    }
}




