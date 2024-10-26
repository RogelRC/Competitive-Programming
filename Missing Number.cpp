#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
 
    vector<int> lista(n - 1);
 
    for(int i = 0; i < n - 1; i ++){
        cin >> lista[i];
    }
 
    sort(lista.begin(), lista.end());
 
    for(int i = 0; i < n - 1; i ++){
        if(lista[i] != i + 1){
            cout << i + 1;
            return 0;
        }
    }
 
    cout << n;
    return 0;
}