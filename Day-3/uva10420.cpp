#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;
struct stats
{
    char country[100];
    int count;
};

stats finalAnswer[2001];
int totalCount=0;

void updateStats(char cn[])
{
    int i;
    for(i=0; i<totalCount; i++)
    {
        if(strcmp(finalAnswer[i].country, cn)==0)
        {
            finalAnswer[i].count++;
            return;
        }
    }
    strcpy(finalAnswer[totalCount].country, cn);
    finalAnswer[totalCount].count  = 1;
    totalCount++;
}

int cmp(const void *a, const void *b)
{
    stats *as, *bs;
    as = (stats *)a;
    bs = (stats *)b;
    return strcmp(as->country, bs->country);
}

void uva10420()
{
    int t, i;
    char line[100];
    char cn[100];
    scanf("%d\n", &t);
    while(t--)
    {
        gets(line);
        sscanf(line, "%s", cn);
        //printf("\n********%s", cn);
        updateStats(cn);
    }

    qsort(finalAnswer, totalCount, sizeof(stats), cmp);

    for(i=0; i<totalCount; i++)
        printf("%s %d\n", finalAnswer[i].country, finalAnswer[i].count);
}


int main()
{
    uva10420();
    return 0;
}



