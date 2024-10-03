#include <bits/stdc++.h>

using namespace std;

vector<int> lista;

void generar(int n, int i){
    int a = ceil(log2(n));

    if(i == ceil((double)a / 2)){
        lista.push_back(n);
        return;
    }

    generar(n, i + 1);
    
    n |= 1 << a - i - 1;
    n |= 1 << i;

    generar(n, i + 1);
}

int buscar(int x){
    int l = 0;
    int r = lista.size() -1;

    int m;

    while(l <= r){

        m = (l+r)/2;

        if(lista[m] == x){
            return m;
        }
        if(lista[m] < x)
            l = m + 1;
        else r = m - 1; 
    }

    return m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lista.push_back(1);
    for(int i=1;i<=30;i++){
    
        generar(pow(2, i) + 1, 1);
    
    }
    
    sort(lista.begin(),lista.end());

    int t;
    cin>>t;

    int a,b;

    while(t--){

        cin>>a>>b;

        int r = buscar(b);
        int l = buscar(a);

        int res = r - l + 1;
        //cout<<l<<' '<<r<<'\n';
        //for(int i=l;i<=r;i++)
          //  cout << bitset<32>(lista[i]) <<'\n';

        if(lista[l]<a)
            res--;
        if(lista[r]>b)
            res--;
        cout<<res<<'\n';
    }

    return 0;
}