#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int FC;
int MC;

int dc[30];
int ds[30];
void setzeroes()
{
    memset(dc, 0, 30*sizeof(int));
    memset(ds, 0, 30*sizeof(int));
}

void fillCapacities(int n)
{
    int i;
    for(i=1; i<=n; i++)
        scanf("%d", &dc[i]);
}

bool isBlownWithProcessSwitching(int m)
{
    int d;
    int tc=0;
    int i;
    bool ans = false;
    for(i=1; i<=m; i++)
    {
        scanf("%d", &d);


        if(ds[d]==0){
            tc+=dc[d];
            if(tc>FC)
                ans = true;
            if(tc>MC)
                MC = tc;
        }
        else
            tc-=dc[d];

        ds[d]=!ds[d];
    }
    return ans;
}
void uva661()
{
    int n, m;
    int seq=1;
    while(1)
    {
        scanf("%d %d %d", &n, &m, &FC);
        if(n==0 && m==0 && FC==0)
            break;

        fillCapacities(n);

        printf("Sequence %d\n", seq++);

        if(isBlownWithProcessSwitching(m))
        {
            printf("Fuse was blown.\n");
        }
        else
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n", MC);
        }
        printf("\n");
        setzeroes();
        MC = 0;
    }
}



