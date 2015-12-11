#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

#define MAX 501

using namespace std;

int board[MAX][MAX];
int freeSpots;
void fillZeroes(int r, int c)
{
    int i, j;
    for(i=1; i<=r; i++)
        for(j=1; j<=c; j++)
            board[i][j] = 0;
}

void markFilled(int x1, int y1, int x2, int y2)
{
    int i,j;
    int t;
    if(x1>x2)
    {
        t = x1;
        x1 = x2;
        x2 = t;
    }
    if(y1>y2)
    {
        t = y1;
        y1 = y2;
        y2 = t;
    }

    for(i=x1; i<=x2; i++)
    {
        for(j=y1; j<=y2; j++)
        {
            if(board[i][j]==0)
            {
                board[i][j]=1;
                freeSpots--;
            }
        }
    }

}
void uva10703()
{
    int W, H, N;
    int sub;
    int x1, y1, x2, y2;
    while(true)
    {
        scanf("%d %d %d", &W, &H, &N);
        if(W==0 && H==0 && N==0)
            break;
        freeSpots = W*H;
        for(sub=1; sub<=N; sub++)
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            markFilled(x1, y1, x2, y2);
        }

        switch(freeSpots){
        case 0:
            printf("There is no empty spots.\n");
            break;
        case 1:
            printf("There is one empty spot.\n");
            break;
        default:
            printf("There are %d empty spots.\n", freeSpots);
        }
        fillZeroes(W, H);
    }
}



