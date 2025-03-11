#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<string, string>> ops(n);
    for (int i = 0; i < n; i++) {
        cin >> ops[i].first >> ops[i].second;
    }
    int m;
    cin >> m;
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        inDegree[b]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (order.size() != n) {
        cout << -1;
        return 0;
    }
    bool state = false;
    int trueCount = 0;
    for (int i : order) {
        if (ops[i].first == "set") {
            if (ops[i].second == "true") {
                if (state) {
                    cout << -1;
                    return 0;
                }
                state = true;
                trueCount++;
            } else {
                if (!state) {
                    cout << -1;
                    return 0;
                }
            }
        } else {
            if (ops[i].second == "true") {
                if (!state) {
                    cout << -1;
                    return 0;
                }
                state = false;
                trueCount++;
            } else {
                if (state) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    if (trueCount > 2) {
        cout << -1;
        return 0;
    }
    for (int i : order) {
        cout << i + 1 << " ";
    }
    return 0;
}