#include <bits/stdc++.h>
 
using namespace std;
 
#define Left(x) ((x << 1) + 1)
#define Right(x) ((x << 1) + 2)
#define MaxN 200005
 
int item[MaxN];
int tree[MaxN * 4];
 
void build(int *st, int node, int nodeL, int nodeR)
{
    if (nodeL == nodeR)
    {
        st[node] = item[nodeL];
        return;
    }
    int m = (nodeL + nodeR) / 2;
 
    build(st, Left(node), nodeL, m);
    build(st, Right(node), m + 1, nodeR);
 
    st[node] = min(st[Left(node)], st[Right(node)]);
}
 
void update(int *st, int node, int nodeL, int nodeR, int pos, int val)
{
    if (nodeL == nodeR)
    {
        st[node] = val;
        return;
    }
    int m = (nodeL + nodeR) / 2;
    if (pos <= m)
        update(st, Left(node), nodeL, m, pos, val);
 
    else
        update(st, Right(node), m + 1, nodeR, pos, val);
 
    st[node] = min(st[Left(node)], st[Right(node)]);
}
int query(int *st, int node, int nodeL, int nodeR, int l, int r)
{
    if (nodeL == l && nodeR == r)
        return st[node];
 
    int m = (nodeL + nodeR) / 2;
 
    if (r <= m)
        return query(st, Left(node), nodeL, m, l, r);
 
    if (l > m)
        return query(st, Right(node), m + 1, nodeR, l, r);
 
    return min(query(st, Left(node), nodeL, m, l, m), query(st, Right(node), m + 1, nodeR, m + 1, r));
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int numeros, querys, a, b, c;
 
    cin >> numeros >> querys;
 
    for(int i = 1; i <= numeros; i ++){
        cin >> item[i];
    }
 
    build(tree, 1, 1, numeros);
 
    while(querys --){
        cin >> a >> b >> c;
 
        if(a == 2){
            cout << query(tree, 1, 1, numeros, b, c) << "\n";
        }
        else{
            update(tree, 1, 1, numeros, b, c);
        }
    }
 
    return 0;
}