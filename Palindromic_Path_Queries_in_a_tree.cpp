
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<int> parent, depth, sz, heavy, head, pos;
    vector<int> bit, masks;
    int timer, n;

    void dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        int maxSize = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];

            if (sz[v] > maxSize) {
                maxSize = sz[v];
                heavy[u] = v;
            }
        }
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u])
                decompose(v, v);
        }
    }

    void updateBIT(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] ^= val;
    }

    int queryBIT(int idx) {
        int res = 0;

        for (++idx; idx > 0; idx -= idx & -idx)
            res ^= bit[idx];

        return res;
    }

    int rangeXor(int l, int r) {
        if (l > r) return 0;

        return queryBIT(r) ^
               (l > 0 ? queryBIT(l - 1) : 0);
    }

    int pathXor(int u, int v) {
        int res = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            res ^= rangeXor(pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        res ^= rangeXor(pos[u], pos[v]);

        return res;
    }

public:
    vector<bool> palindromePathQueries(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;

        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        sz.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        masks.assign(n, 0);
        bit.assign(n + 1, 0);
        timer = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        decompose(0, 0);

        for (int i = 0; i < n; i++) {
            masks[i] = 1 << (s[i] - 'a');
            updateBIT(pos[i], masks[i]);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                int newMask = 1 << (c - 'a');

                updateBIT(pos[u], masks[u] ^ newMask);
                masks[u] = newMask;
            } else {
                int u, v;
                ss >> u >> v;

                int mask = pathXor(u, v);

                bool ok = (mask == 0) ||
                          ((mask & (mask - 1)) == 0);

                ans.push_back(ok);
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> edges(n - 1, vector<int>(2));

    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<string> queries(q);

    for (int i = 0; i < q; i++) {
        string type;
        cin >> type;

        if (type == "update") {
            int u;
            char c;
            cin >> u >> c;

            queries[i] = type + " " + to_string(u) + " " + c;
        } else {
            int u, v;
            cin >> u >> v;

            queries[i] = type + " " +
                         to_string(u) + " " + to_string(v);
        }
    }

    Solution sol;
    vector<bool> ans =
        sol.palindromePathQueries(n, edges, s, queries);

    cout << "[";

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) cout << ", ";

        cout << (ans[i] ? "true" : "false");
    }

    cout << "]\n";

    return 0;
}
