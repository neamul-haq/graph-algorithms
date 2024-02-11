//https://cses.fi/problemset/task/1668   --> cses building teams
//TC:O(V*(V+E)) -> O(v^2+VE)
//SC:O(N^2)

#include<bits/stdc++.h>
using namespace std;

const int N=2e5;

int visited[N],color[N];

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

        for(int adj_node:adj_list[head])
        {
            if(visited[adj_node]==0)
            {
                visited[adj_node]=1;
                q.push(adj_node);
                if(color[head]==1)  color[adj_node]=2;
                else color[adj_node]=1;
            }
            else
            {
            //check if color is diff or same
                if(color[head]==color[adj_node])
                {
                    return false;
                }
            }
        }
    }
    return true;
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

    bool is_bicolorable = true;

    for(int i=1; i<=nodes; i++){
        if(visited[i]==0)
        {
            color[i]=1;
           bool ok =  bfs(i);
           if(!ok)
           {
               is_bicolorable=false;
               break;
           }
        }
    }

    if(!is_bicolorable)
    {
        cout << "IMPOSSIBLE" << "\n";
    }
    else{
        for(int i=1; i<=nodes; i++)
        {
            cout << color[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2
*/
