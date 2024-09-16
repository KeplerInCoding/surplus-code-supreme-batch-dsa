 int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<int>visited(V, 0);
        vector<int>parent(V, -1);
        vector<int>wt(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        pq.push({0, 0});
        wt[0]=0;
        int ans = 0;
        
        while(!pq.empty()){
            int w = pq.top().first;
            int src = pq.top().second;
            pq.pop();
            
            if(visited[src])continue;
            visited[src]=1;
            ans+=w;
            
            for(auto k:adj[src]){
                int nbh=k[0];
                int w=k[1];
                if(!visited[nbh] && wt[nbh]>w){
                    wt[nbh]=w;
                    parent[nbh]=src;
                    pq.push({w, nbh});
                }
            }
        }
        
        return ans;
    }