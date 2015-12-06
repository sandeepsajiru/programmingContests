#define V   4
#define COLORS  5

#include <stdbool.h>
#include <stdio.h>

bool graphMatrix[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0},
};

int solutionColoring[V];

void printColoringSolution(int vertices)
{
    int i;
    printf("\nCOLORING:\n");
    for(i=0; i<vertices; i++)
        printf("%d ", solutionColoring[i]);
    printf("\n");
}

bool isValidColor(int i, int c)
{
    int j;
    for(j=0; j<V; j++)
        if(graphMatrix[i][j]!=0 && solutionColoring[j]==c)
            return false;
    return true;
}
bool coloringProblemHelper(int vi, int colorCount)
{
    if(vi==V)
    {
        printColoringSolution(V);
        return true;
    }
    int c;
    for(c=1; c<=colorCount; c++)
    {
        if(isValidColor(vi, c))
        {
            solutionColoring[vi] = c;
            if(coloringProblemHelper(vi+1, colorCount))
                return true;
            solutionColoring[vi] = 0;
        }

    }
    return false;

}
void coloringProblem(int c)
{
    if(!coloringProblemHelper(0, c))
        printf("SOLUTION DOESNT EXIST");
}
