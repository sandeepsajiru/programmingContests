#include <cstdio>
#include <stack>
#include <set>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 100

int d[MAX][MAX];
bool visited[MAX];
long vertices[MAX];
int tv=0;

int getIndex(int v)
{
    int i;
    for(i=0;i<tv;i++)
        if(vertices[i]==v)
            return i;
    return -1;
}

void reportAnswer(int s, int ttl, int CASE)
{
    int si = getIndex(s);
    queue< pair<int, int> > q;
    pair<int, int> p;
    int notReachable;
    q.push(make_pair(si, ttl));
    visited[si] = true;
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
    for(int i=0;i<tv;i++)
    {
        if(visited[i]==false)
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
            if(getIndex(v)==-1)
                vertices[tv++]=v;
            if(getIndex(u)==-1)
                vertices[tv++]=u;
            d[getIndex(u)][getIndex(v)] = d[getIndex(v)][getIndex(u)] = 1;
        }

        // Read Query
        int s, ttl;
        bool isSNew = false;
        while(scanf("%d %d", &s, &ttl)==2 && !(s==0 && ttl==0))
        {
            // VERY VERY TRICKY TEST CASE
            // S IS A NEW NODE THAT HASN'T BEEN INTRODUCED BEFORE QUERY
            // AND SHOULDN'T BE CONSIDERED AFTER QUERY
            if(getIndex(s)==-1){
                vertices[tv++]=s;
                isSNew = true;
            }
            reportAnswer(s, ttl, CASE);
            memset(visited, 0, sizeof(visited));

            // VERY VERY TRICKY TEST CASE
            // S IS A NEW NODE THAT HASN'T BEEN INTRODUCED BEFORE QUERY
            // AND SHOULDN'T BE CONSIDERED AFTER QUERY
            if(isSNew)
            {
                tv--;
                isSNew = false;
            }
            CASE++;
        }

        // Reset Network Connectivity Matrix
        memset(d, 0, sizeof(d));
        memset(d, 0, sizeof(vertices));
        tv=0;
    }
}

int main()
{
    uva336();
    //printf("%d", sizeof(d));

    return 0;
}
