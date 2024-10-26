#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> lista;
vector<int> tree;
 
void Build(int p, int l, int r){
    if(l == r)tree[p] = lista[l];
 
    else{
        int mid = (l + r) / 2;
 
        Build(p * 2, l, mid);
        Build(p * 2 + 1, mid + 1, r);
 
        tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
    }
}
 
int Query(int p, int l, int r, int a, int b){
    if(a > b)return INT_MAX;
 
    if(l == a && r == b)return tree[p];
 
    int mid = (l + r) / 2;
    return min(Query(p * 2, l, mid, a, min(b, mid)), Query(p * 2 + 1, mid + 1, r, max(a, mid + 1), b));
}
 
int main(){
    int cantidad, querys,a , b;
    cin >> cantidad >> querys;
 
    lista.resize(cantidad + 1);
    tree.resize((cantidad + 1) * 4);
 
    for(int i = 1; i <= cantidad; i ++){
        cin >> lista[i];
    }
 
    Build(1, 1, cantidad);
 
    while(querys--){
        cin >> a >> b;
 
        cout << Query(1, 1, cantidad, a, b) << "\n";
    }
 
    return 0;
}