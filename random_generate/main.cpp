#include <iostream>
#include <vector>
#include <algorithm>  
#include <cstdlib>
#include <ctime>

class Graph {
public:
    Graph(int vertices, int edges);
    void generateGraph();
    void displayGraph();

private:
    int vertices;
    int edges;
    std::vector<std::vector<int>> adjList;
};

Graph::Graph(int vertices, int edges) : vertices(vertices), edges(edges) {
    adjList.resize(vertices);
}

void Graph::generateGraph() {
    srand(time(0));
    for (int i = 0; i < edges; ++i) {
        int u = rand() % vertices;
        int v = rand() % vertices;
        while (u == v || std::find(adjList[u].begin(), adjList[u].end(), v) != adjList[u].end()) {
            u = rand() % vertices;
            v = rand() % vertices;
        }
        adjList[u].push_back(v);
        adjList[v].push_back(u);  
    }
}

void Graph::displayGraph() {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << ":";
        for (int j : adjList[i]) {
            std::cout << " " << j;
        }
        std::cout << std::endl;
    }
}

int main() {
    int vertices, edges;
    std::cout << "Enter the number of vertices: ";
    std::cin >> vertices;
    std::cout << "Enter the number of edges: ";
    std::cin >> edges;

    Graph graph(vertices, edges);
    graph.generateGraph();
    graph.displayGraph();

    return 0;
}
