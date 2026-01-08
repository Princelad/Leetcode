#include <bits/stdc++.h>
using namespace std;

// Pattern: disjoint set union (union-find) for connectivity queries.
// Supports union by size and path compression.
// Time: alpha(n) per op (inverse Ackermann) ; Space: O(n)
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a; size[a] += size[b];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int comps = n;
        for (auto& e : edges) if (dsu.unite(e[0], e[1])) --comps;
        return comps;
    }
};
