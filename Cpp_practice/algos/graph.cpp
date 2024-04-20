#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    vector<int> traversal;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        traversal.push_back(current);

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return traversal;
}
/*the BFS function takes a graph represented as an adjacency list and a start node as input. 
It uses a queue to keep track of the nodes to visit and a visited array to keep track of the nodes that have already been visited.
The function returns a vector containing the order in which the nodes were visited during the BFS traversal.*/
int main() {
    vector<vector<int>> graph = {{1, 2},
                                 {0, 3, 4},
                                 {0, 5},
                                 {1},
                                 {1},
                                 {2}};

    vector<int> traversal = bfs(graph, 0);

    for (int node : traversal) {
        cout << node << " ";
    }

    return 0;
}