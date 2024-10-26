#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct datos {
    long long node, cost, coupon_used;
    bool operator>(const datos &other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> adj(n + 1);
    for (long long i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<vector<long long>> dist(n + 1, vector<long long>(2, INF));
    priority_queue<datos, vector<datos>, greater<datos>> pq;

    dist[1][0] = 0;
    pq.push({1, 0, 0});

    while (!pq.empty()) {
        datos cur = pq.top();
        pq.pop();

        long long node = cur.node, cost = cur.cost, coupon_used = cur.coupon_used;

        if (cost > dist[node][coupon_used]) continue;

        for (auto &edge : adj[node]) {
            long long next_node = edge.first;
            long long flight_cost = edge.second;

            if (dist[next_node][coupon_used] > dist[node][coupon_used] + flight_cost) {
                dist[next_node][coupon_used] = dist[node][coupon_used] + flight_cost;
                pq.push({next_node, dist[next_node][coupon_used], coupon_used});
            }

            if (!coupon_used) {
                long long discounted_cost = flight_cost / 2;
                if (dist[next_node][1] > dist[node][0] + discounted_cost) {
                    dist[next_node][1] = dist[node][0] + discounted_cost;
                    pq.push({next_node, dist[next_node][1], 1});
                }
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << "\n";

    return 0;
}
