#include <bits/stdc++.h>
 
using namespace std;
 
long long n, m, e1, e2, p;
 
const long long MaxN = 2505;
 
struct Edge {
    long long src, dst, weight;
    Edge(long long a, long long b, long long c) : src(a), dst(b), weight(c) {}
};
 
vector<Edge> edges;
vector<long long> dist;
vector<bool> visited;
 
void dfs(long long node, vector<vector<long long>>& adj) {
    visited[node] = true;
    for (long long neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj);
        }
    }
}
 
bool Bellman_Ford(long long s) {
    dist = vector<long long>(n + 1, INT64_MIN / 2);
    dist[s] = 0;
 
    for (long long i = 0; i < n - 1; ++i) {
        for (auto& e : edges) {
            long long u = e.src;
            long long v = e.dst;
            long long w = e.weight;
 
            if (dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
 
    vector<vector<long long>> adj(n + 1);
    for (auto& e : edges) {
        adj[e.src].push_back(e.dst);
    }
 
    for (auto& e : edges) {
        long long u = e.src;
        long long v = e.dst;
        long long w = e.weight;
 
        if (dist[u] + w > dist[v]) {
            //cout << u << " " << v << "\n";
            fill(visited.begin(), visited.end(), false);
            dfs(1, adj);
            bool a = visited[u];
 
            fill(visited.begin(), visited.end(), false);
            dfs(u, adj);
            a = a && visited[n];
 
            //cout << "V: " << visited[u] << " " << visited[n] << "\n";
 
 
            if(a == true) return false;
        }
    }
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
 
    visited.resize(n + 1);
 
    for (long long i = 0; i < m; i++) {
        cin >> e1 >> e2 >> p;
        edges.push_back({e1, e2, p});
    }
 
    if (!Bellman_Ford(1)) {
        cout << -1;
    } else {
        cout << dist[n];
    }
 
    return 0;
}