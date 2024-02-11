//https:cses.fi/problemset/task/1667
//TC:O(V^2)
//SC:O(V^2)
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

const int N=2e4;

int visited[N],level[N],parent[N];

int adj_list[N][N];

void bfs(int src, int n)
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


        for(int i=1; i<=n; i++)
        {
            if(adj_list[head][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                level[i]=level[head] + 1;
                parent[i]=head;
                q.push(i);
            }
        }
    }
}

int main()
{

    int n, edges;
    cin >> n >> edges;

    for(int i=0; i<edges; i++)
    {
        int u , v;
        cin >> u >> v;
        adj_list[u][v]=1;
        adj_list[v][u]=1;
    }

    int src=1;
    bfs(src,n);
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
