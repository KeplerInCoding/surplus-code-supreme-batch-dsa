//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// directed & undirected
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>visited(N, 0);
        vector<int>dist(N, -1);
        
        vector<vector<int>> v(N);
        for(int i=0; i<edges.size(); i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int>q;
        q.push(src);
        visited[src]=1;
        dist[src]=0;
        
        while(!q.empty()){
            int k = q.front();
            q.pop();
            
            for(auto nbh:v[k]){
                if(visited[nbh]==1)continue;
                dist[nbh]=dist[k]+1;
                q.push(nbh);
                visited[nbh]=1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends