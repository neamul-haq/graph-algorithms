//TC:O(V+E)
//SC:O(V)
#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int visited[N];

vector<int>adj_list[N];

bool bfs(int src)
{
    queue<int>q;
    visited[src]=1;

    q.push(src);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        if(head==6) return true;
        //cout << head << endl;

        for(int adj_node:adj_list[head])
        {
            if(visited[adj_node]==0)
            {
                visited[adj_node]=1;
                q.push(adj_node);

            }
        }
    }
    return false;
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

    int src=2;
    cout << bfs(src) << endl;
    return 0;
}

/*
9 12
0 2
7 8
0 4
0 5
6 7
1 4
1 5
2 3
2 4
4 5
8 6
1 6
*/
