#include <bits/stdc++.h>

using namespace std;

int Solve(){
    int soldados, pain, a, m = 0;
    priority_queue<int> cola;

    cin >> soldados >> pain;

    while(soldados --){
        cin >> a;

        cola.push(a);
    }

    while(!cola.empty()){
        a = cola.top();
        cola.pop();

        pain -= a;
        a /= 2;
        m ++;

        if(a > 0) cola.push(a);
        if(pain <= 0) return m;
    }

    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos;

    cin >> casos;

    while(casos --){
        int aaa = Solve();

        if(aaa == 0) cout << "Evacuate\n";
        else cout << aaa << "\n";

    }

    return 0;
}
