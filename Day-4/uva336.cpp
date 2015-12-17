#include <cstdio>
#include <stack>
#include <set>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 1000

int d[MAX][MAX];
bool visited[MAX];
set<int> vertices;

void reportAnswer(int s, int ttl, int CASE)
{
    queue< pair<int, int> > q;
    pair<int, int> p;
    int notReachable;
    q.push(make_pair(s, ttl));
    visited[s] = true;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p.second!=0)
        {
            for(int i=0;i<MAX;i++)
            {
                if(d[p.first][i]==1 && visited[i]==false){
                    q.push(make_pair(i, p.second-1));
                    visited[i] = true;
                }
            }
        }
    }

    notReachable= 0 ;
    for(set<int>::iterator it=vertices.begin();it!=vertices.end();++it)
    {
        if(visited[*it]==false)
            notReachable++;
    }

    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", CASE, notReachable, s, ttl);
}
void uva336()
{
    int NC;
    int CASE=1;
    while(scanf("%d", &NC)==1 && NC!=0)
    {
        // Read Pairs and Mark Connectivity
        int u,v;
        while(NC--)
        {
            scanf("%d %d", &u, &v);
            vertices.insert(u);
            vertices.insert(v);
            d[u][v] = d[v][u] = 1;
        }

        // Read Query
        int s, ttl;
        while(scanf("%d %d", &s, &ttl)==2 && !(s==0 && ttl==0))
        {
            reportAnswer(s, ttl, CASE);
            memset(visited, 0, sizeof(visited));
            CASE++;
        }

        // Reset Network Connectivity Matrix
        memset(d, 0, sizeof(d));
        vertices.clear();
    }
}

int main()
{
    uva336();
    //printf("%d", sizeof(d));

    return 0;
}
