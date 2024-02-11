//TC:O(V+E)
//SC:O(V)
#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int cnt[N];
int visited[N];

vector<int>adj_list[N];

void bfs(int src)
{
    queue<int>q;
    visited[src]=1;

    q.push(src);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();

        cout << head << endl;

        for(int adj_node:adj_list[head])
        {
            cnt[adj_node]++;
            if(visited[adj_node]==0)
            {
                visited[adj_node]=1;
                q.push(adj_node);
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
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src=1;
    bfs(src);

    for(int i=1; i<=nodes; i++)
    {
        cout << i << "-->" << cnt[i] << endl;
    }
    return 0;
}

/*
5 6
1 2
2 3
3 4
4 5
1 3
2 4
*/
