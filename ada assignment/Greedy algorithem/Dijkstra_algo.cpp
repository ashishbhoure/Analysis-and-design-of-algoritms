/*Ques: Implement the Dijkstra algorithm to find the shortest path between two vertices in a
graph in Cpp*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// A class to represent a directed graph, with edge weights
class Graph {
private:
    int V; // number of vertices
    vector<vector<pair<int, int>>> adj; // adjacency list: pair(vertex, weight)
public:
    Graph(int V);
    void add_edge(int u, int v, int w);
    vector<int> dijkstra(int src);
};

// Constructor to initialize a graph with V vertices
Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

// Adds a directed edge with weight w from vertex u to vertex v
void Graph::add_edge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
}

// Dijkstra's algorithm to find the shortest path from src to all other vertices
vector<int> Graph::dijkstra(int src) {
    // Initialize distances to all vertices as infinite and src as 0
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    // Create a priority queue to store vertices and their minimum distances from src
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    
    while (!pq.empty()) {
        // Get the minimum distance vertex from the priority queue
        int u = pq.top().second;
        pq.pop();
        
        // Update distance of adjacent vertices if they can be reached with less weight
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main() {
    Graph g(5);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 1);
    g.add_edge(2, 1, 2);
    g.add_edge(2, 3, 5);
    g.add_edge(3, 4, 3);
    g.add_edge(1, 4, 4);

    vector<int> dist = g.dijkstra(0);
    
    cout << "Shortest distances from vertex 0 to all other vertices: ";
    for (int i = 0; i < dist.size(); ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}
