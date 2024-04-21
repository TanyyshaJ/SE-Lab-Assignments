#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
private:
    int numNodes;
    vector<vector<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfsUtil(int u, vector<bool>& visited, vector<int>& dfsTraversal) {
        visited[u] = true;
        dfsTraversal.push_back(u);

        for (int v : adjList[u]) {
            if (!visited[v]) {
                dfsUtil(v, visited, dfsTraversal);
            }
        }
    }

public:
    Graph() : numNodes(0) {}

    void readGraph() {
        cout << "Enter the number of nodes: ";
        cin >> numNodes;
        adjList.resize(numNodes);

        cout << "Enter the edges (u v) or (-1 -1) to stop:\n";
        int u, v;
        cin >> u >> v;
        while (u != -1 && v != -1) {
            addEdge(u, v);
            cin >> u >> v;
        }
    }

    void displayAdjList() {
        cout << "Adjacency List:\n";
        for (int u = 0; u < numNodes; u++) {
            cout << u << ": ";
            for (int v : adjList[u]) {
                cout << v << " ";
            }
            cout << "\n";
        }
    }

    void DFS(int start) {
        vector<bool> visited(numNodes, false);
        vector<int> dfsTraversal;

        dfsUtil(start, visited, dfsTraversal);

        cout << "DFS Traversal: ";
        for (int u : dfsTraversal) {
            cout << u << " ";
        }
        cout << "\n";
    }

    void BFS(int start) {
        vector<bool> visited(numNodes, false);
        vector<int> bfsTraversal;
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            bfsTraversal.push_back(u);

            for (int v : adjList[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << "BFS Traversal: ";
        for (int u : bfsTraversal) {
            cout << u << " ";
        }
        cout << "\n";
    }

    void inOutDegree(int node) {
        unordered_set<int> neighbors;
        int inDegree = 0, outDegree = 0;

        for (int u = 0; u < numNodes; u++) {
            for (int v : adjList[u]) {
                neighbors.insert(v);
                if (u == node) {
                    outDegree++;
                }
            }
        }

        for (int v : adjList[node]) {
            neighbors.erase(v);
        }

        inDegree = neighbors.size();

        cout << "Indegree of node " << node << ": " << inDegree << "\n";
        cout << "Outdegree of node " << node << ": " << outDegree << "\n";
    }

    bool isConnected() {
        vector<bool> visited(numNodes, false);
        int start = 0;

        for (int u = 0; u < numNodes; u++) {
            if (!visited[u]) {
                vector<int> dfsTraversal;
                dfsUtil(u, visited, dfsTraversal); // Pass it by reference
            }
        }

        for (bool visited_node : visited) {
            if (!visited_node) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Graph g;
    int choice, startNode, node;

    do {
        cout << "\nGraph Operations Menu:\n";
        cout << "1. Read Graph\n";
        cout << "2. Display Adjacency List\n";
        cout << "3. Perform DFS\n";
        cout << "4. Perform BFS\n";
        cout << "5. Calculate Indegree and Outdegree\n";
        cout << "6. Check if Graph is Connected\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.readGraph();
                break;
            case 2:
                g.displayAdjList();
                break;
            case 3:
                cout << "Enter the start node for DFS: ";
                cin >> startNode;
                g.DFS(startNode);
                break;
            case 4:
                cout << "Enter the start node for BFS: ";
                cin >> startNode;
                g.BFS(startNode);
                break;
            case 5:
                cout << "Enter the node to calculate indegree and outdegree: ";
                cin >> node;
                g.inOutDegree(node);
                break;
            case 6:
                if (g.isConnected()) {
                    cout << "The graph is connected.\n";
                } else {
                    cout << "The graph is not connected.\n";
                }
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}