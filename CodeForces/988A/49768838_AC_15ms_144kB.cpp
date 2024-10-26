#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, T, n;
    map<int, int> mapa;
    vector<int> sol;

    cin >> N >> T;


    for(int i = 0; i < N; i ++){
        cin >> n;

        if(mapa[n] == 0){
            mapa[n] = i + 1;
        }
    }

    if(mapa.size() < T) cout << "NO";
    else{
        cout << "YES\n";

        for(auto i: mapa){
            sol.push_back(i.second);
        }

        sort(sol.begin(), sol.end());

        for(int i = 0; i < T; i ++){
            cout << sol[i] << " ";
        }
    }

    return 0;
}