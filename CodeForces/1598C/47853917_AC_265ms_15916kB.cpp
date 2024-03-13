#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long casos, cantidad, n, sol, media;
    map<long long, long long> mapa;

    cin >> casos;

    while(casos --){
        mapa.clear();
        sol = 0;
        media = 0;

        cin >> cantidad;

        for(long long i = 0; i < cantidad; i ++){
            cin >> n;

            media += n;

            mapa[n] ++;
        }

        media *= 2;

        if(media % cantidad != 0){
            cout << "0\n";
            continue;
        }

        media /= cantidad;

        for(auto i: mapa){
            long long a1 = i.first;
            long long a2 = media - a1;

            if(mapa[a2] > 0){
                if(a1 == a2) sol += (i.second * (i.second - 1));
                else sol += i.second * mapa[a2];
            }
        }

        cout << sol / 2 << "\n";
    }

    return 0;
}