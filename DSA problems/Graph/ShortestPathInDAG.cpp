

// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>degree(N, 0);
        vector<int> topo;
        
        vector<vector<pair<int, int>>> v(N);
        for(int i=0; i<edges.size(); i++){
            v[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            degree[edges[i][1]]++;
        }
        
        queue<int>q;
        
        for(int i=0; i<N; i++){
            if(degree[i]==0)
            q.push(i);
        }
        
        while(!q.empty()){
            int k = q.front();
            q.pop();
            topo.push_back(k);
            
            for(auto i : v[k]){
                degree[i.first]--;
                if(degree[i.first]==0){
                    q.push(i.first);
                }
            }
            
        }
        
        
        vector<int>dist(N, INT_MAX);
        dist[0]=0;
        
        for(int i:topo){
            if(dist[i]==INT_MAX) continue;
            for(auto j:v[i]){
                dist[j.first]=min(dist[j.first], dist[i]+j.second);
            }
            
        }
        
        for(int i=0; i<dist.size(); i++){
            if(dist[i]==INT_MAX)dist[i]=-1;
        }
        return dist;
    }
};


