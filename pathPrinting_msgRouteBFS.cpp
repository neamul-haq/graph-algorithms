//https:cses.fi/problemset/task/1667
//TC:O(V+E)
//SC:O(V+E)
/*
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5
*/
#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

int visited[N],level[N],parent[N];

vector<int>adj_list[N];

void bfs(int src)
{
    queue<int>q;
    visited[src]=1;
    level[src]=1;
    parent[src]=-1;
    q.push(src);

    while(!q.empty())
    {
        int head = q.front();
        q.pop();


        for(int adj_node:adj_list[head])
        {
            if(visited[adj_node]==0)
            {
                visited[adj_node]=1;
                level[adj_node]=level[head] + 1;
                parent[adj_node]=head;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    int n, edges;
    cin >> n >> edges;

    for( int i=0; i<edges; i++)
    {
        int u , v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src=1;
    bfs(src);
    if(visited[n]==0)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }

    cout << level[n] << "\n";
    vector<int>path;
    int selected_node = n;

    while(true)
    {
        path.push_back(selected_node);
        if(selected_node == 1) break;
        selected_node = parent[selected_node];
    }

    reverse(path.begin(), path.end());

    for(int node: path)
    {
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}
