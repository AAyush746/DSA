#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    Graph g(arr);

    cout << "Graph adjacency matrix:\n";
    g.printGraph();

    cout << "Number of edges: " << g.numEdges() << endl;
    cout << "In-degree of vertex 3: " << g.indegree(4) << endl;
    cout << "Out-degree of vertex 2: " << g.outdegree(5) << endl;
    cout << "Degree of vertex 3: " << g.degree(3) << endl;

    vector<int> neighbours = g.neighbours(3);
    cout << "Neighbours of vertex 3: ";
    for (int v : neighbours) {
        cout << v << " ";
    }
    cout << endl;

    cout << "Are vertex 2 and vertex 3 neighbours? " << (g.areNeighbours(4, 5) ? "Yes" : "No") << endl;

    return 0;
}
