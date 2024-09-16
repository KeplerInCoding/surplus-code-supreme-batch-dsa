int findParent(vector<int> &parent, int node){
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]); //path compression
    }
    
    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
        if(rank[u]>=rank[v]){
            parent[v]=u;
            rank[u]++;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
    
    
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int, int>>> edges;
        
        for (int u = 0; u < V; u++) {
            for (auto &edge : adj[u]) {
                int v = edge[0];
                int weight = edge[1];
                edges.push_back({weight, {u, v}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        vector<int>rank(V, 0);
        vector<int>parent(V);
        
        for(int i=0; i<parent.size(); i++) parent[i]=i;
        
        int ans = 0;
        
        for (auto &edge : edges){
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            u = findParent(parent, u);
            v = findParent(parent, v);
            
            if(u!=v){
                unionSet(u, v, parent, rank);
                ans += w;
            }
        }
        
        return ans;
    }