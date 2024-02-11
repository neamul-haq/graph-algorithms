#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=505;
const ll INF = 1e18;
ll visited[N], parent[N];
ll d[N];

vector<pair<ll, ll>>adj_list[N];
ll nodes, edges;

void dijkstra(ll src)
{
    for(ll i=1; i<=nodes; i++)
    {
        d[i] = INF;
    }
    for(ll i=1; i<=nodes; i++)
    {
        visited[i] = 0;
    }
    d[src]=0;

    priority_queue<pair<ll, ll>>pq;
    pq.push({0, src});

    while(!pq.empty())
    {

        pair<ll, ll> head = pq.top();
        pq.pop();

        ll selected_node = head.second;
        if(visited[selected_node])
        {
            continue;
        }

        visited[selected_node]=1;

        for(auto adj_entry:adj_list[selected_node])
        {
            ll adj_node = adj_entry.first;
            ll edge_cst = adj_entry.second;

            if(d[selected_node]+edge_cst < d[adj_node])
            {
                d[adj_node] = d[selected_node]+edge_cst;
                parent[adj_node] = selected_node;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;

    for( ll i=0; i<edges; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src =1;
    dijkstra(src);
    if(visited[nodes]==0)
    {
        cout << -1 << "\n";
        return 0;
    }
    vector<int>path;
    int selected_node = nodes;

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
