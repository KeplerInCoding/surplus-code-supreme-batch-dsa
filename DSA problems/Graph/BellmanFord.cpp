vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V, INT_MAX);
            
        dist[S]=0;
        
        
        for(int i=0; i<V-1; i++){
            for(auto k:edges){
                int u=k[0];
                int v=k[1];
                int w=k[2];
                if(dist[u] != INT_MAX && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        
        bool flag=false;
        for(auto k:edges){
            int u=k[0];
            int v=k[1];
            int w=k[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                return { -1 };
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = 100000000;  
            }
        }
        return dist;
        
        
    }