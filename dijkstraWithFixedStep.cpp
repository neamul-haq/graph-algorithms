int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];

        for(auto x : flights) {
            adj[x[0]].push_back({ x[1]  ,  x[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        // stops , node , distance
        q.push({ 0 , { src ,0}});
        vector<int>dist(n , 1e8);

        while(!q.empty()) {
            int nextnode = q.front().second.first;
            int stops = q.front().first;
            int cost = q.front().second.second;
            q.pop();

            if(stops > k) {
                continue;
            }

            for(auto x  : adj[nextnode]) {
                int adjnode = x.first;
                int newcost = x.second;

                if(cost + newcost < dist[adjnode] && stops<= k ) {
                    dist[adjnode] = cost + newcost;
                    q.push({ stops + 1 , { adjnode , cost + newcost  }});
                }
            }
        }

        if( dist[dst] == 1e8) {
            return -1;
            // cycle with -ve weight
        }


        return dist[dst];
    }
