#define N_QUEEN_SOLUTION_SIZE   8
#define QUEEN_COUNT 8
#include <stdbool.h>
#include <stdio.h>

int nQueenSolution[N_QUEEN_SOLUTION_SIZE][N_QUEEN_SOLUTION_SIZE];

bool isRowClear(int x)
{
    int j;
    for(j=0;j<N_QUEEN_SOLUTION_SIZE;j++)
        if(nQueenSolution[x][j]!=0)
        return false;
    return true;
}
bool isColClear(int y)
{
    int j;
    for(j=0;j<N_QUEEN_SOLUTION_SIZE;j++)
        if(nQueenSolution[j][y]!=0)
        return false;
    return true;
}
bool isLTRBDiagonalClear(int x, int y)
{
    int i=x, j=y;
    // Up
    while(i>=0 && j>=0)
    {
        if(nQueenSolution[i][j]!=0)
            return false;
        i = i-1;
        j = j-1;
    }

    i=x+1;
    j=y+1;

    // Down
    while(i<N_QUEEN_SOLUTION_SIZE && j<N_QUEEN_SOLUTION_SIZE)
    {
        if(nQueenSolution[i][j]!=0)
            return false;
        i = i+1;
        j = j+1;
    }

    return true;
}
bool solved=false;
bool isLBRTDiagonalClear(int x, int y)
{
    int i=x, j=y;
    // Up
    while(i>=0 && j<N_QUEEN_SOLUTION_SIZE)
    {
        if(nQueenSolution[i][j]!=0)
            return false;
        i = i-1;
        j = j+1;
    }

    i=x+1;
    j=y-1;

    // Down
    while(i<N_QUEEN_SOLUTION_SIZE && j>=0)
    {
        if(nQueenSolution[i][j]!=0)
            return false;
        i = i+1;
        j = j-1;
    }

    return true;
}
bool isValidQueenPlacement(int x, int y)
{
    return isRowClear(x) && isColClear(y) && isLTRBDiagonalClear(x, y) && isLBRTDiagonalClear(x,y);
}

void printNQueenSolution()
{
    printf("\n\nSOLUTION: \n");
    int i, j;
    for(i=0; i<N_QUEEN_SOLUTION_SIZE; i++)
    {
        for(j=0; j<N_QUEEN_SOLUTION_SIZE; j++)
            printf("%2d ", nQueenSolution[i][j]);

        printf("\n");
    }
}

void solveNQueenHelper(int x, int y, int qNum)
{
    if(qNum==QUEEN_COUNT+1)
    {
        printNQueenSolution();
        solved=true;
        return;
    }

    if(!isValidQueenPlacement(x, y))
        return;

    nQueenSolution[x][y] = qNum;
    //printNQueenSolution();
    int i;
    for(i=0;i<N_QUEEN_SOLUTION_SIZE;i++)
    {
        solveNQueenHelper(i, y+1, qNum+1);
        if(solved)
            return;
    }
    nQueenSolution[x][y] = 0;
    //printNQueenSolution();
}

void solveNQueen()
{
    int i;
    for(i=0;i<N_QUEEN_SOLUTION_SIZE;i++)
        if(!solved)
            solveNQueenHelper(i, 0, 1);

    if(!solved)
        printf("NO SOLUTION");
}
