#include <stdio.h>
#include <stdlib.h>

int sol[20];
int i=0;
void printSolution()
{
    int j;
    for(j=0;j<i;j++)
        printf("%d ", sol[j]);
    printf("\n");
}
void printAllPossibleChangeInternal(int d[], int n, int m, int j)
{
    if(m<0)
        return;
    if(m==0){
        printSolution();
        return;
    }

    // With j
    sol[i] = d[j];
    i++;
    printAllPossibleChangeInternal(d, n, m-d[j], j);


    // Without j
    i--;
    if(j+1<n)
        printAllPossibleChangeInternal(d, n, m, j+1);
}

void printAllPossibleChange(int d[], int n, int m)
{
    printAllPossibleChangeInternal(d, n, m, 0);
}
int printAllPossibleChangeTest()
{
    int d[] = {1, 5, 7, 9};
    int n = sizeof(d)/sizeof(int);
    int m =10;
    printAllPossibleChange(d, n, m);
    return 0;
}
