#include <bits/stdc++.h>

using namespace std;

vector<int> padre, tam;

int find(int u) {
    if (padre[u] != u) {
        padre[u] = find(padre[u]);
    }
    return padre[u];
}

void unir(int u, int v) {
    int a = find(u);
    int b = find(v);
    if (a != b) {
        if (tam[a] < tam[b]) {
            swap(a, b);
        }
        padre[b] = a;
        tam[a] += tam[b];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    padre.resize(n);
    tam.resize(n, 1);
    for (int i = 0; i < n; i++) {
        padre[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        if (k == 0) continue;

        vector<int> grupo(k);
        for (int j = 0; j < k; j++) {
            cin >> grupo[j];
            grupo[j]--;
        }

        for (int j = 1; j < k; j++) {
            unir(grupo[0], grupo[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << tam[find(i)] << " ";
    }

    return 0;
}