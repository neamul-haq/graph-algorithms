//TC: O(E*V) or n*m
//SC: O(E) or m

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;

int d[N];
vector<vector<int>>edge_list;
int main()
{

    int n, m;
    cin >> n >> m;

    for(int i = 1 ; i <=  n ; i++)
    {
        d[i] = INF;
    }

    for(int i = 0 ; i < m ; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge_list.push_back({ u, v, w });
    }


    int src = 1;

    d[src] = 0;


    for(int i = 1 ; i <= n-1 ; i++)
    {
        for(int node = 1 ; node <= n ; node++)
        {
            for(int i=0; i<3; i++)
            {
                int u = edge_list[node][0];
                int v = edge_list[node][1];
                int w = edge_list[node][2];

                if(d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                }
            }
        }
    }

    for(int i = 1 ; i <= n ; i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;
    return 0;
}
