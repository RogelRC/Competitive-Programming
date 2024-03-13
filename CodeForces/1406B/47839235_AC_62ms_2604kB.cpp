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

    int casos, cantidad, n;
    long long sol;

    vector<long long> positivos;
    vector<long long> negativos;

    cin >> casos;

    while(casos --){
        positivos.clear();
        negativos.clear();
        sol = INT64_MIN;

        cin >> cantidad;

        while(cantidad --){
            cin >> n;

            if(n >= 0) positivos.push_back(n);
            else negativos.push_back(n);
        }

        sort(positivos.begin(), positivos.end(), cmp());
        sort(negativos.begin(), negativos.end());

        if(positivos.size() >= 5){
            sol = max(sol, positivos[0] * positivos[1] * positivos[2] * positivos[3] * positivos[4]);
        }
        if(positivos.size() >= 3 && negativos.size() >= 2){
            sol = max(sol, positivos[0] * positivos[1] * positivos[2] * negativos[0] * negativos[1]);
        }
        if(positivos.size() >= 1 && negativos.size() >= 4){
            sol = max(sol, positivos[0] * negativos[0] * negativos[1] * negativos[2] * negativos[3]);
        }

        if(sol == INT64_MIN){
            sol = 1;
            int p, n;
            
            for(int i = 0; i < 5; i ++){
                p = n = INT_MAX;

                if(positivos.size() >= 1) p = positivos.back();
                if(negativos.size() >= 1) n = abs(negativos.back());

                if(p < n){
                    sol *= positivos.back();
                    positivos.pop_back();
                }
                else{
                    sol *= negativos.back();
                    negativos.pop_back();
                }
            }
        }

        cout << sol << "\n";
    }

    return 0;
}