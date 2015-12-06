
#define V   5
#include <stdbool.h>
#include <stdio.h>

bool graphHamMatrix[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0},
};
int path[V+1];
int visited[V];

bool isValidHamCycleVertex(int v)
{
    if(visited[v]==false)
        return true;
    return false;
}

bool areAllVisited()
{
    int i;
    for(i=0;i<V;i++)
        if(visited[i]==false)
            return false;

    return true;
}

bool hamiltonianCycle(int pi, int si, int ei)
{
    int i;
    if(si==ei && areAllVisited())
    {
        for(i=0; i<V+1; i++)
            printf("%d ", path[i]);
        printf("%d", si);
        printf("\n");
        return true;
    }

    for(i=0; i<V; i++)
    {
        if(graphHamMatrix[si][i]!=0 && visited[i]==false)
        {
            path[pi] = i;
            visited[i] = true;
            if(hamiltonianCycle(pi+1, i, ei))
                return true;
            visited[i] = false;
        }
    }

    return false;
}

void hamiltonianCycleMain()
{
    hamiltonianCycle(0, 0, 0);
}
