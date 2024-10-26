#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    int components, largest;

    DSU(int n) : parent(n+1), size(n+1, 1), components(n), largest(1) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if (a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            if (size[rootA] < size[rootB]) {
                swap(rootA, rootB);
            }
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
            size[rootB] = 0;

            components--;
            largest = max(largest, size[rootA]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        dsu.unite(a, b);
        cout << dsu.components << " " << dsu.largest << "\n";
    }

    return 0;
}
