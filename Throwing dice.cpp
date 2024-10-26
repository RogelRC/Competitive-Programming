#include <bits/stdc++.h>

using namespace std;

#define double long double

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    
    cin >> M >> N;

    vector<int> A(M);
    vector<int> B(N);

    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    double E_A = 0.0;
    for (int i = 0; i < M; ++i) {
        E_A += (A[i] + 1) / 2.0;
    }


    double E_B = 0.0;
    for (int i = 0; i < N; ++i) {
        E_B += (B[i] + 1) / 2.0;
    }

    if (E_A > E_B) {
        cout << "ALICE\n";
    }
    else if (E_A < E_B) {
        cout << "BOB\n";
    }
    else {
        cout << "TIED\n";
    }

    return 0;
}
