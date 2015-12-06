#define N   7
#include <stdbool.h>
#include <stdio.h>

int set[N] = {10, 7, 5, 18, 12, 20, 15};
int answer[N];
int visited[N];

bool isOkToIncludeCurrentElement(int i, int k)
{
    if(set[i]<=k && visited[i]==false)
        return true;
    return false;
}


void solveSubSetSumHelper(int si, int ai, int k)
{
    if(k<0)
        return;
    if(k==0)
    {
        int i;
        for(i=0; i<ai; i++)
            printf("%d ", answer[i]);
        printf("\n");
        return;
    }

    int i;
    for(i=si; i<N; i++)
    {
        if(isOkToIncludeCurrentElement(i, k))
        {
            answer[ai] = set[i];
            solveSubSetSumHelper(i+1, ai+1, k-answer[ai]);
        }
    }
}

void solveSubSetSum(int k)
{
    solveSubSetSumHelper(0, 0, k);
}
