#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n, a, dinero, arr[1000001];
 
    for(int i = 0; i < 1000001; i ++){
        arr[i] = 1000000000;
    }
 
    cin >> n >> dinero;
 
    vector<int> moneda(n);
 
    for(int i = 0; i < n; i ++){
        cin >> a;
        arr[a] = 1;
 
        for(int j = 1; j <= dinero; j ++){
            if(j - a >= 1){
                arr[j] = min(arr[j], arr[j - a] + 1);
            }
        }
    }
 
    if(arr[dinero] != 1000000000)cout << arr[dinero];
    else cout << -1;
    return 0;
}