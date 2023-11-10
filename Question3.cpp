#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isBipartite(int N, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(N);
    for (auto edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    vector<int> colors(N, -1);
    for (int i = 0; i < N; ++i) {
        if (colors[i] == -1) {
            colors[i] = 0;
            vector<int> stack = { i };
            while (!stack.empty()) {
                int node = stack.back();
                stack.pop_back();
                for (int neighbor : graph[node]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - colors[node];
                        stack.push_back(neighbor);
                    }
                    else if (colors[neighbor] == colors[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void generateGrayCode(int n) {
    for (int i = 0; i < (1 << n); ++i) {
        int gray = i ^ (i >> 1);
        // Reversing bits 0 and 1
        int reversedGray = 0;
        while (gray) {
            reversedGray <<= 2;
            reversedGray |= gray & 3;
            gray >>= 2;
        }
        for (int j = n - 1; j >= 0; --j) {
            cout << ((reversedGray >> j) & 1) << " ";
        }
        cout << endl;
    }
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<pair<int, int>> edges;
    cout << "Enter the edges (format: node1 node2):" << endl;

    for (int i = 0; i < numEdges; ++i) {
		int u, v;    // u and v are nodes
		cin >> u >> v;      
		edges.push_back({ u, v });
	}

    // Determine if the graph is bipartite  

    bool isBipartiteGraph = isBipartite(numNodes, edges);

    if (isBipartiteGraph) {
		cout << "The graph is bipartite." << endl;
	}
	else {
		cout << "The graph is not bipartite." << endl;
	}
    //  Generate a six-bit Gray code with bit reversal 0 1 1 0
    cout << "Six-bit Gray code with bit reversal 0 1 1 0:" << endl;
    generateGrayCode(6);


    return 0;
    }




