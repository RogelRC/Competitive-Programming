#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, n, q;
    set<int> s;

    cin >> cantidad >> q;

    vector<int> v(cantidad + 1), otro(cantidad + 1);

    for(int i = 1; i <= cantidad; i++){
        cin >> v[i];
    }

    for(int i = cantidad; i >= 1; i --){
        s.insert(v[i]);
        otro[i] = s.size();
    }

    while(q --){
        cin >> n;

        cout << otro[n] << "\n";
    }

}