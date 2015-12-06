#define N   8
#define M   8
#define PRINT_ALL_SOLUTIONS 0

#include <stdbool.h>
#include <stdio.h>

int solution[N][N];
int solutionNumber = 1;
/**/
int xMoves[M] = { 1, 2, -1, -2, -2, -1,  1,  2 };
int yMoves[M] = { 2, 1,  2,  1, -1, -2, -2, -1 };


/*
int xMoves[] = { 2, 2,  1, 1, -2, -2, -1, -1};
int yMoves[] = {-1, 1, -2, 2, -1,  1, -2,  2};
*/


void printSolution()
{
    printf("\n\nSOLUTION: %d\n", solutionNumber++);
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            printf("%2d ", solution[i][j]);

        printf("\n");
    }
}

bool isValidMove(int i, int j)
{
    if(i>=0 && i<N && j>=0 && j<N && solution[i][j]==0)
        return true;
    return false;
}

void solveKTHelper(int cx, int cy, int moveNumber)
{
    if(!PRINT_ALL_SOLUTIONS && solutionNumber>1)
        return;

    if(moveNumber==N*N+1)
    {
        printSolution();
        return;
    }

    int mc;
    int nx, ny;
    for(mc=0; mc<M; mc++)
    {
        ny = cy + xMoves[mc];
        nx = cx + yMoves[mc];

        if(isValidMove(nx, ny))
        {
            solution[nx][ny] = moveNumber;
            solveKTHelper(nx, ny, moveNumber+1);
            solution[nx][ny] = 0;
        }
    }
}

void solveKnightTour()
{
    int moveNumber = 1;
    int cx = 0 ;
    int cy = 0;
    solution[cx][cy] = moveNumber;

    solveKTHelper(cx, cy, moveNumber+1);

    if(solutionNumber==1)
        printf("NO SOLUTION FOUND");
}

void knightTourTest()
{
    solveKnightTour();
}
