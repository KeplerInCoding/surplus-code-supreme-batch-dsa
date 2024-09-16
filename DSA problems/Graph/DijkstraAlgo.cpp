
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    //for positive weight graph
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V, INT_MAX);
        dist[S]=0;
        
        set<pair<int, int>>s;
        s.insert({0, S});
        
        while(!s.empty()){
            auto it = s.begin();
            int d = it->first;
            int u = it->second;
            s.erase(it);
            
            for(auto v: adj[u]){
                if(dist[v[0]]>d+v[1]){
                    if(dist[v[0]]!=INT_MAX){
                        s.erase({dist[v[0]], v[0]});
                    }
                    dist[v[0]]=dist[u]+v[1];
                    s.insert({dist[v[0]], v[0]});
                }
            }
        }
        return dist;
    }
};


-----------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> pii; // Pair of (distance, vertex)

void dijkstra(int start, const vector<vector<pii>>& graph) {
    int n = graph.size();
    vector<int> distances(n, numeric_limits<int>::max()); // Distance array
    distances[start] = 0;

    // Min-heap priority queue to store (distance, vertex) pairs
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start}); // Push the start vertex with distance 0

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // Skip if we have found a shorter path already
        if (current_dist > distances[current_node])
            continue;

        // Explore all neighbors of the current node
        for (const pii& neighbor : graph[current_node]) {
            int neighbor_node = neighbor.first;
            int weight = neighbor.second;
            int new_dist = current_dist + weight;

            // If a shorter path is found
            if (new_dist < distances[neighbor_node]) {
                distances[neighbor_node] = new_dist;
                pq.push({new_dist, neighbor_node});
            }
        }
    }

    // Output the shortest distances
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (distances[i] == numeric_limits<int>::max())
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << distances[i] << "\n";
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pii>> graph(n);

    // Add edges (for an undirected graph)
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[2].push_back({3, 4});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});

    int start_node = 0;
    dijkstra(start_node, graph);

    return 0;
}


