#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct bnds
{
    int lower, upper;
};
struct aps
{

    int ba;
    int eSize;
    int dim;
    char arrName[15];
    bnds bnd[20];
    int c[20];
};

int N, R;

aps ap[100];
int dims[20];

int getArrayIndex(char an[])
{
    int i;
    for(i=0;i<N;i++)
        if(strcmp(an, ap[i].arrName)==0)
            return i;
    return -1;
}
void uva394()
{

    int i, j;
    char an[15];

    scanf("%d %d", &N, &R);

    for(i=0;i<N;i++)
    {
        scanf("%s %d %d %d", ap[i].arrName, &ap[i].ba, &ap[i].eSize, &ap[i].dim);

        //printf("%s %d %d %d ", ap[i].arrName, ap[i].ba, ap[i].eSize, ap[i].dim);

        for(j=0;j<ap[i].dim;j++){
            scanf("%d %d", &(ap[i].bnd[j].lower), &(ap[i].bnd[j].upper));
            //printf("%d %d ", ap[i].bnd[j].lower, ap[i].bnd[j].upper);
        }
        //printf("\n");

    }


    for(i=0;i<R;i++)
    {
        scanf("%s", an);
        int aidx = getArrayIndex(an);

        printf("%s[", an);
        for(j=0;j<ap[aidx].dim;j++){
            scanf("%d", &dims[j]);
            if(j==ap[aidx].dim-1)
                printf("%d] = ", dims[j]);
            else
                printf("%d, ", dims[j]);
        }

        int ans = 50;  // TODO:  CALCULATE IT WITH GIVEN FORMULA


        printf("%d\n", ans);

    }


}
