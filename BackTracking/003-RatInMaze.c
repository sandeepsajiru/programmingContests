#define N   4
#define M   4
#include <stdbool.h>
#include <stdio.h>

int maze[N][N] =
{
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
};

int xMazeMoves[] = {1, 0, -1,  0};
int yMazeMoves[] = {0, 1,  0, -1};

bool mazeSolved = 0;

void printMaze()
{
    int x, y;
    printf("\nMAZE:\n");
    for(x=0; x<N; x++)
    {
        for(y=0; y<N; y++)
            printf("%d ", maze[x][y]);
        printf("\n");
    }
}
bool isValidMazeMove(int x, int y)
{
    return (x>=0 && x<N && y>=0 && y<N && maze[x][y]==1);
}

void solveRatMaze(int cx, int cy)
{
    if(cx==N-1 && cy==N-1)
    {
        printMaze();
        mazeSolved = 1;
        return;
    }

    int nx, ny, mc;
    for(mc=0; mc<M; mc++)
    {
        nx = cx+yMazeMoves[mc];
        ny = cy+xMazeMoves[mc];

        if(isValidMazeMove(nx, ny))
        {
            maze[nx][ny] = 9;

            solveRatMaze(nx, ny);
            if(mazeSolved)
                return;

            maze[nx][ny] = 1;
        }
    }
}

void ratInMazeTest()
{
    maze[0][0] = 9;
    solveRatMaze(0, 0);

    if(mazeSolved==0)
        printf("NO SOLUTION");
}
