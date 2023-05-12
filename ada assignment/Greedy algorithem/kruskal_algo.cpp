/*Ques: Implement Kruskal's algorithm to find the minimum spanning tree of a given graph
in Cpp*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// edge struct for storing edges
struct Edge {
    int u, v, w;
};

// disjoint set struct for cycle detection
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) {
            return;
        }
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

// function to find minimum spanning tree using Kruskal's algorithm
vector<Edge> kruskal(vector<Edge>& edges, int n) {
    vector<Edge> result;
    DisjointSet dsu(n);

    // sort edges by weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    for (Edge& e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.merge(e.u, e.v);
            result.push_back(e);
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    vector<Edge> mst = kruskal(edges, n);

    for (Edge& e : mst) {
        cout << e.u << " " << e.v << " " << e.w << endl;
    }

    return 0;
}
