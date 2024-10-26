#include <bits/stdc++.h>

using namespace std;

#define NMAX 200005

long long lista[NMAX];
long long tree[NMAX * 4];
long long dp[NMAX * 4];
long long dpl[NMAX * 4];
long long dpr[NMAX * 4];
long long cantidad;

void build(long long p, long long l, long long r){
    if(l == r){
        tree[p] = dp[p] = dpl[p] = dpr[p] = lista[l];
        return;
    }

    long long mid = (l + r) / 2;

    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);

    dpl[p] = max(dpl[2 * p], tree[2 * p] + dpl[2 * p + 1]);
    dpr[p] = max(dpr[2 * p + 1], tree[2 * p + 1] + dpr[2 * p]);
    dp[p] = max(dpr[2 * p] + dpl[2 * p + 1], max(dp[2 * p], dp[2 * p + 1]));
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

long long pos, val;
void update(long long p, long long l, long long r){
    if(l == r){
        tree[p] = dp[p] = dpl[p] = dpr[p] = val;
        return;
    }

    long long mid = (l + r) / 2;

    if(pos <= mid) update(p * 2, l, mid);
    else update(p * 2 + 1, mid + 1, r);

    dpl[p] = max(dpl[2 * p], tree[2 * p] + dpl[2 * p + 1]);
    dpr[p] = max(dpr[2 * p + 1], tree[2 * p + 1] + dpr[2 * p]);
    dp[p] = max(dpr[2 * p] + dpl[2 * p + 1], max(dp[2 * p], dp[2 * p + 1]));
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long querys;

    cin >> cantidad >> querys;

    for(long long i = 1; i <= cantidad; i ++){
        cin >> lista[i];
    }

    build(1, 1, cantidad);

    while (querys --){
        cin >> pos >> val;

        update(1, 1, cantidad);

        cout << max((long long)0, dp[1]) << "\n";
    }
    

    return 0;
}