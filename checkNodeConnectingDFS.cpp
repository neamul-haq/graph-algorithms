#include<bits/stdc++.h>
using namespace std;

const int N=1e5;

int visited[N];

vector<int>adj_list[N];

bool dfs(int node)
{
    //cout<<node<<endl;
    visited[node]=1;
    if(node==6) return true;
    for(int adj_node : adj_list[node])
    {
        if(visited[adj_node]==0)
        {
            if(dfs(adj_node))
            {
                return true;
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
    cout << dfs(src) << endl;
    return 0;
}



//Chat GPT
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> adj_list; // adjacency list
//vector<bool> visited; // visited array
//
//bool dfs(int curr, int target) {
//    visited[curr] = true;
//    if (curr == target) {
//        return true;
//    }
//    for (int neighbor : adj_list[curr]) {
//        if (!visited[neighbor]) {
//            if (dfs(neighbor, target)) {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int main() {
//    int V, E; // number of vertices and edges
//    cin >> V >> E;
//    adj_list.resize(V);
//    visited.resize(V, false);
//    for (int i = 0; i < E; i++) {
//        int u, v;
//        cin >> u >> v;
//        adj_list[u].push_back(v);
//        adj_list[v].push_back(u);
//    }
//    bool connected = dfs(2, 6);
//    if (connected) {
//        cout << "Nodes 2 and 6 are connected." << endl;
//    } else {
//        cout << "Nodes 2 and 6 are not connected." << endl;
//    }
//    return 0;
//}
