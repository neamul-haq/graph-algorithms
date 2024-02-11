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

int visited[N],parent[N];

vector<int>adj_list[N];

void dfs(int node)
{
    visited[node]=1;

    for(int adj_node : adj_list[node])
    {
        if(visited[adj_node]==0)
        {
            parent[adj_node]=node;
            dfs(adj_node);
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
    parent[src]=-1;
    dfs(src);
    if(visited[n]==0)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }


    vector<int>path;
    int selected_node = n;

    while(true)
    {
        path.push_back(selected_node);
        if(selected_node == 1) break;
        selected_node = parent[selected_node];
    }

    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    for(int node: path)
    {
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}

/*
6 6
1 2
2 4
2 3
4 5
3 5
5 6
output:1 2 4 5 6
*/
