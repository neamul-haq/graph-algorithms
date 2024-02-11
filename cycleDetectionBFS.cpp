//https://cses.fi/problemset/task/1678    -->round trip ii
//TC:O(v+E)
//SC:O(V)

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
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
        cout << head << endl;
        for(int adj_node:adj_list[head])
        {
            if(visited[adj_node]==0)
            {
                visited[adj_node]=1;
                q.push(adj_node);
            }
            else if(visited[adj_node] == 1)
            {
                return true;
            }
        }
        visited[head]=2;
    }
    return false;
}



int main()
{
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool cycle_exist = false;

    for(int i=1; i<=n; i++)
    {
        if(visited[i]==0)
        {
            bool got_cycle = bfs(i);
            if(got_cycle)
            {
                cycle_exist = true;
                break;
            }
        }
    }

    if(cycle_exist)
    {
        cout << "Cycle exists" << "\n";
    }
    else {
        cout << "No Cycle" << "\n";
    }
}

/*
4 4
1 3
2 1
2 4
3 4

output: no cycle
*/
