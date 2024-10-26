#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, cantidad;
    long long alice, bob;
    vector<int> lista;

    cin >> casos;

    while(casos --){
        cin >> cantidad;

        alice = bob = 0;
        lista.resize(cantidad);

        for(int i = 0; i < cantidad; i ++){
            cin >> lista[i];
        }

        sort(lista.begin(), lista.end(), cmp());

        for(int i = 0; i < cantidad; i ++){
            if(i % 2 == 0 && lista[i] % 2 == 0){
                alice += lista[i];
            }
            else if(i % 2 == 1 && lista[i] % 2 == 1){
                bob += lista[i];
            }
        }

        if(alice > bob) cout << "Alice\n";
        else if(bob > alice) cout << "Bob\n";
        else cout << "Tie\n";

    }

    return 0;
}