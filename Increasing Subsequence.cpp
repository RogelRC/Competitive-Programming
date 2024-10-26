#include <bits/stdc++.h>
 
using namespace std;
 
const int oo = INT_MAX;
 
#define index_of(as, x) distance(as.begin(), lower_bound(as.begin(), as.end(), x))
 
vector<int> lis_fast(const vector<int> &a){
    const int n = a.size();
    vector<int> A(n, oo), id(n);
 
    for(int i = 0; i < n; ++ i){
        id[i] = index_of(A, a[i]);
        A[id[i]] = a[i];
    }
 
    int m = *max_element(id.begin(), id.end());
 
    vector<int> b(m + 1);
 
    for(int i = n - 1; i >= 0; -- i){
        if(id[i] == m){
            b[m --] = a[i];
        }
    }
 
    return b;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int cantidad;
 
    cin >> cantidad;
 
    vector<int> lista(cantidad);
 
    for(int i = 0; i < cantidad; i ++){
        cin >> lista[i];
    }
 
    cout << lis_fast(lista).size();
 
    return 0;
}