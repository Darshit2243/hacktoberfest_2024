#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(const vector<vector<int>>& graph, vector<bool>& visited, int currPos, int n, int count, int cost, int& ans) {
    // Base case: all cities are visited, return to the starting city
    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        return ans;
    }

    // Try all cities as the next position
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i]) {
            visited[i] = true;
            tsp(graph, visited, i, n, count + 1, cost + graph[currPos][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> graph = { {0, 10, 15, 20},
                                  {10, 0, 35, 25},
                                  {15, 35, 0, 30},
                                  {20, 25, 30, 0} };

    vector<bool> visited(n, false);
    visited[0] = true; // Start from the first city
    int ans = INT_MAX;

    cout << "Minimum travel cost: " << tsp(graph, visited, 0, n, 1, 0, ans) << endl;

    return 0;
}
