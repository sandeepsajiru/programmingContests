#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;
#define CHARS_COUNT 280

int costs[CHARS_COUNT];
void setCostZeroes()
{
    memset(costs, 0, sizeof(char)*CHARS_COUNT);
}

int getLineCost(char line[])
{
    int j;
    int lc=0;
    for(j=0;line[j]!='\0';j++)
        lc += costs[(int)line[j]];
    return lc;
}

void uva11340()
{
    int t, K, i, lc;
    char line[10005];
    scanf("%d", &t);
    char c;
    int ccost;
    while(t-->0)
    {
        scanf("%d", &K);

        fflush(stdin);

        for(i=1;i<=K;i++){
            gets(line);
            sscanf(line, "%c %d", &c, &ccost);
            costs[(int)c] = ccost;
            //printf("'%c' %d\n", c, ccost);
        }

        scanf("%d", &lc);
        fflush(stdin);
        //printf("LC: %d\n", lc);
        int totalCost=0;
        for(i=1;i<=lc;i++)
        {
            gets(line);
            totalCost += getLineCost(line);
        }

        printf("%.2f$\n", totalCost/100.0);
        setCostZeroes();
    }
}
