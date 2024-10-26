#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, sol = 0;
    vector<int> hombres;
    vector<int> mujeres;

    cin >> n;
    hombres.resize(n);

    for(int i = 0; i < n; i ++){
        cin >> hombres[i];
    }

    cin >> m;
    mujeres.resize(m);

    for(int i = 0; i < m; i ++){
        cin >> mujeres[i];
    }

    sort(hombres.begin(), hombres.end());
    sort(mujeres.begin(), mujeres.end());

    int i = 0, j = 0;

    while(i < n && j < m){
        if(abs(hombres[i] - mujeres[j]) <= 1){
            sol ++;
            i ++;
            j ++;
        }
        else if(hombres[i] > mujeres[j]){
            j ++;
        }
        else{
            i ++;
        }
    }

    cout << sol;

    return 0;
}