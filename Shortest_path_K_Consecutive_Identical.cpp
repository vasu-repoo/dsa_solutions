
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <climits>
#include <functional>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int> >& edges,
                     string labels, int k) {

        // Build adjacency list
        vector<vector<pair<int, int> > > adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back(make_pair(v, w));
        }

        const long long INF = LLONG_MAX;

        // dist[node][consecutive count]
        vector<vector<long long> > dist(
            n, vector<long long>(k + 1, INF)
        );

        // Min heap: {cost, node, count}
        typedef tuple<long long, int, int> State;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        // Starting node
        dist[0][1] = 0;
        pq.push(make_tuple(0, 0, 1));

        while (!pq.empty()) {

            State current = pq.top();
            pq.pop();

            long long cost = get<0>(current);
            int u = get<1>(current);
            int cnt = get<2>(current);

            // Skip outdated states
            if (cost != dist[u][cnt]) {
                continue;
            }

            // Destination reached
            if (u == n - 1) {
                return (int)cost;
            }

            // Explore neighbours
            for (int i = 0; i < adj[u].size(); i++) {

                int v = adj[u][i].first;
                int w = adj[u][i].second;

                int newCnt;

                if (labels[u] == labels[v]) {
                    newCnt = cnt + 1;
                } 
                else {
                    newCnt = 1;
                }

                // Invalid consecutive sequence
                if (newCnt > k) {
                    continue;
                }

                long long newCost = cost + w;

                // Relaxation
                if (newCost < dist[v][newCnt]) {

                    dist[v][newCnt] = newCost;

                    pq.push(make_tuple(
                        newCost, v, newCnt
                    ));
                }
            }
        }

        return -1;
    }
};

int main() {

    Solution sol;

    // Example 1
    int n = 3;

    vector<vector<int> > edges;

    edges.push_back({0, 1, 1});
    edges.push_back({1, 2, 1});
    edges.push_back({0, 2, 3});

    string labels = "aab";
    int k = 1;

    cout << "Output: "
         << sol.shortestPath(n, edges, labels, k)
         << endl;

    return 0;
}
