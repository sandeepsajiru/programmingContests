#include <stdio.h>
#include <stdlib.h>

int table[10][10];
int getChangeCoinCount(int d[], int n, int m)
{
    int i;
    for (i=0; i<m; i++)
        table[0][i] = 1;
    int j;
    for (i = 1; i < n+1; i++)
    {
        int x,y;
        for (j = 0; j < m; j++)
        {
            // Count of solutions including d[j]
            x = (i-d[j] >= 0)? 1+table[i - d[j]][j]: n+1;

            // Count of solutions excluding d[j]
            y = (j >= 1)? table[i][j-1]: n+1;

            // total count
            table[i][j] = x<y?x:y;
        }
    }

    return table[n][m-1];
}
int main()
{
    int d[] = {1, 5, 7, 9};
    int n = sizeof(d)/sizeof(int);
    int m =10;
    printf("%d", getChangeCoinCount(d, n, m));
    return 0;
}
