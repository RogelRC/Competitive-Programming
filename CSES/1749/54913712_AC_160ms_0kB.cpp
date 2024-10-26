#include <bits/stdc++.h>

using namespace std;

vector<int> ft;
vector<int> lista;
int cantidad;

int lowbit(int x) { return x & -x; }

void update(int pos, int val)
{
    for (; pos < (int)ft.size(); pos += lowbit(pos))
        ft[pos] += val;
}

int query(int pos)
{
    int sum = 0;
    for (; pos > 0; pos -= lowbit(pos))
        sum += ft[pos];
    return sum;
}

int query(int l, int r)
{
    l = (l > 0) ? l - 1 : 0;
    return query(r) - query(l);
}

int highestOneBit(int n)
{
    int shift = 31 - (__builtin_clz(n));
    int ans = 1;
    ans <<= shift;
    return ans;
}

int lower_bound(int sum)
{
    --sum;
    int pos = 0;
    for (int blockSize = highestOneBit(ft.size()); blockSize; blockSize >>= 1)
    {
        int nextPos = pos + blockSize;
        if (nextPos < (int)ft.size() && sum >= ft[nextPos])
        {
            sum -= ft[nextPos];
            pos = nextPos;
        }
    }
    return pos + 1;
}

int getZeros(int x) { return x < 0 ? 0 : x + 1 - query(x); }

int getZeros(int x1, int x2)
{
    int s = getZeros(x2) - getZeros(x1 - 1);
    return x1 <= x2 ? s : s + getZeros(ft.size() - 1);
}

int f, sol;
int bb(int a, int b){
    if(a > b) return 0;
    if(a == b){
        sol = a;
        return query(a);
    }

    int mid = (a + b) / 2;

    int q = query(mid);

    if(f == q){
        return bb(a, mid);
    }
    else if(f < q) return bb(a, mid);
    else return bb(mid + 1, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> cantidad;

    ft.resize(cantidad + 1);
    lista.resize(cantidad + 1);

    for(int i = 1; i <= cantidad; i ++){
        cin >> lista[i];

        update(i, 1);
    }

    for(int i = 1; i <= cantidad; i ++){
        cin >> f;

        bb(1, cantidad);

        cout << lista[sol] << " ";

        update(sol, -1);
    }

    return 0;
}