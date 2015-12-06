#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int i, int j)
{
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}
void permute(int a[], int stIdx, int endIdx)
{
    int i;
    if(stIdx == endIdx)
    {
        for(i=0; i<=endIdx; i++)
            printf("%d", a[i]);
        printf("\n");
    }
    else
    {
        for(i=stIdx; i<=endIdx; i++)
        {
            swap(a, stIdx, i);
            permute(a, stIdx+1, endIdx);
            swap(a, stIdx, i);
        }
    }
}
void permuteTest()
{
    int a[] = {1, 2, 3};
    int n = sizeof(a)/sizeof(int);
    permute(a, 0, n-1);
}
