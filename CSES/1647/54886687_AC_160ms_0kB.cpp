#include <bits/stdc++.h>

using namespace std;

#define NMAX 200005

int cantidad, querys, a, b;
int lista[NMAX];
int tree[NMAX * 4];

void build(int p, int l, int r){
    if(l == r){
        tree[p] = lista[l];
        return;
    }

    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);

    tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
}

int solve(int p, int a, int b, int l, int r){
    if(a == l && b == r) return tree[p];

    int mid = (a + b) / 2;

    if(r <= mid) return solve(p * 2, a, mid, l, r);
    if(l > mid) return solve(p * 2 + 1, mid + 1, b, l, r);
    return min(solve(p * 2, a, mid, l, mid), solve(p * 2 + 1, mid + 1, b, mid + 1, r));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> cantidad >> querys;

    for(int i = 1; i <= cantidad; i ++){
        cin >> lista[i];
    }

    build(1, 1, cantidad);

    while(querys --){
        cin >> a >> b;
        cout << solve(1, 1, cantidad, a, b) << "\n";
    }


    return 0;
}