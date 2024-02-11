//TC:O(V^2)
//SC:O(V^2)
#include<bits/stdc++.h>
using namespace std;

const int N=20;

int visited[N+3];
int M[N][N]={};

void dfs(int src)
{
    cout << src << endl;
    visited[src]=1;

    for(int i=0; i<=N; i++)
    {
        if(M[src][i]==1 && visited[i]==0)
            {
                dfs(i);
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
    dfs(src);
    return 0;
}
