#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    long long   sol = 0;
    cin >> n;
 
    vector<int> lista(n);
 
    for(int i = 0; i < n; i ++){
        cin >> lista[i];
 
        if(i > 0){
            if(lista[i] < lista[i - 1]){
                sol += lista[i - 1] - lista[i];
                lista[i] = lista[i - 1];
            }
        }
    }
 
    cout << sol;
    return 0;
}