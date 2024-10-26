#include <bits/stdc++.h>

using namespace std;

#define NMAX 200005

#define min(a, b) a ^ b

long long cantidad, querys, a, b, c;
long long lista[NMAX];
long long tree[NMAX * 4];

void build(long long p, long long l, long long r){
    if(l == r){
        tree[p] = lista[l];
        return;
    }

    long long mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);

    tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
}

long long pos, val;
void update(long long p, long long a, long long b){
    if(a == b){
        tree[p] = val;
        return;
    }
    long long mid = (a + b) / 2;
    if(pos <= mid){
        update(p * 2, a, mid);
    }
    else{
        update(p * 2 + 1, mid + 1, b);
    }
    tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
}

long long solve(long long p, long long a, long long b, long long l, long long r){
    if(a == l && b == r) return tree[p];

    long long mid = (a + b) / 2;

    if(r <= mid) return solve(p * 2, a, mid, l, r);
    if(l > mid) return solve(p * 2 + 1, mid + 1, b, l, r);
    return min(solve(p * 2, a, mid, l, mid), solve(p * 2 + 1, mid + 1, b, mid + 1, r));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> cantidad >> querys;

    for(long long i = 1; i <= cantidad; i ++){
        cin >> lista[i];
    }

    build(1, 1, cantidad);

    c = 2;
    while(querys --){
        //cin >> c;

        if(c == 1){
            cin >> pos >> val;

            update(1, 1, cantidad);
        }
        else{
            cin >> a >> b;

            cout << solve(1, 1, cantidad, a, b) << "\n";
        }
    }


    return 0;
}