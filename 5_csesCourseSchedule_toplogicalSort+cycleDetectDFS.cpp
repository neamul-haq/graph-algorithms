//TC:O(V+E)
//SC:O(V)

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int visited[N];
vector<int>adj_list[N];
stack<int>node_stack;

bool dfs(int node)
{
    visited[node] = 1;

    for(int adj_node: adj_list[node])
    {
        if(visited[adj_node] == 0)
        {
            bool got_cycle = dfs(adj_node);
            if(got_cycle)
            {
                return true;
            }
        }
        else if(visited[adj_node] == 1)
        {
            return true;
        }
    }
    visited[node]=2;
    node_stack.push(node);
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
    }

    for(int i=1; i<=n; i++)
    {
        if(visited[i]==0)
        {
            bool is_cycle = dfs(i);
            if(is_cycle){
                cout << "IMPOSSIBLE" << "\n";
                return 0;
            }
        }
    }

    while(!node_stack.empty())
    {
        cout << node_stack.top() << " ";
        node_stack.pop();
    }
    cout << '\n';
    return 0;

}
