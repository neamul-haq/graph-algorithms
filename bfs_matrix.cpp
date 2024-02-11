//TC:O(V^2)
//SC:O(V^2)
#include<bits/stdc++.h>
using namespace std;

const int n=10;
int M[n+2][n+2]={};
int visited[n+2];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=1;

    while(!q.empty())
    {
        int head = q.front();
        q.pop();

        cout << head << endl;

        for(int i=0; i<=n; i++)
        {
            if(M[head][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for( int i=0; i<edges; i++)
    {
        int u , v;
        cin >> u >> v;
        M[u][v]=1;
        M[v][u]=1;
    }

    int src=1;
    bfs(src);
    return 0;
}
