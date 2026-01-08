#include <bits/stdc++.h>
using namespace std;

// Pattern: Dijkstra for non-negative edge weights using min-heap.
// Time: O((V + E) log V) ; Space: O(V + E)
class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src) {
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;
        using State = pair<int, int>; // {dist, node}
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({ 0, src });
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue; // stale state
            for (auto [v, w] : adj[u]) {
                int nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({ nd, v });
                }
            }
        }
        return dist;
    }
};
