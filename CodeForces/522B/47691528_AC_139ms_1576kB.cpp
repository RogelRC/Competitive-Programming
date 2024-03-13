#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, altomax1 = INT_MIN, altomax2 = INT_MIN;

    cin >> cantidad;

    vector<int> l(cantidad + 1), a(cantidad + 1);

    for(int i = 1; i <= cantidad; i ++){
        cin >> l[i] >> a[i];

        l[i] += l[i - 1];

        if(a[i] > altomax1){
            altomax2 = altomax1;
            altomax1 = a[i];
        }

        else if(a[i] > altomax2)altomax2 = a[i];
    }

    for(int i = 1; i <= cantidad; i ++){
        int mul;

        if(altomax1 == a[i])mul = altomax2;
        else mul = altomax1;

        cout << (l[cantidad] - l[i] + l[i - 1]) * mul << " ";
    }


    return 0;
}