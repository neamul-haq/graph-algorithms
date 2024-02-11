//https://cses.fi/problemset/task/1678    -->round trip ii
//TC:O(v+E)
//SC:O(V)

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int visited[N],parent[N];
vector<int>adj_list[N];
int cycleStart=-1;
bool dfs(int node)
{
    visited[node] = 1;

    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            parent[adj_node] = node;
            bool got_cycle = dfs(adj_node);
            if(got_cycle)
            {
                return true;
            }
        }
        else if(visited[adj_node] == 1 && parent[node]!=adj_node)
        {
            parent[adj_node]=node;
            cycleStart=adj_node;
            return true;
        }
    }
    visited[node]=2;
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
            bool got_cycle = dfs(i);
            if(got_cycle)
            {
                cycle_exist = true;
                break;
            }
        }
    }

    if(!cycle_exist)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }

        vector<int>path;
        int selected_node = cycleStart;
        int cnt=0;
        while(true)
        {
            path.push_back(selected_node);
            if(selected_node == cycleStart && cnt>0) break;
            selected_node = parent[selected_node];
            cnt++;
        }

        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for(int node: path)
        {
            cout << node << " ";
        }
        cout << "\n";
}



/*
4 4
1 3
2 1
2 4
3 4

output: no cycle
*/
