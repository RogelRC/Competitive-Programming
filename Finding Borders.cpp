#include <bits/stdc++.h>

using namespace std;

vector<int> prefixFunction(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }

    return pi;
}

vector<int> findBorders(const string &s) {
    vector<int> pi = prefixFunction(s);
    vector<int> borders;
    
    int n = s.size();
    int k = pi[n - 1];

    while (k > 0) {
        borders.push_back(k);
        k = pi[k - 1];
    }

    reverse(borders.begin(), borders.end());
    return borders;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    vector<int> borders = findBorders(s);

    for (int len : borders) {
        cout << len << " ";
    }

    return 0;
}
