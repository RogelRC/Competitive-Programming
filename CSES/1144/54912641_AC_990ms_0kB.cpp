#include <bits/stdc++.h>

using namespace std;

vector<int> ft, copia, copia2;
vector<pair<char, pair<int, int>>> qqq;
map<int, int> mapa;

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cantidad, querys, e = 1, a, b;
    char car;

    cin >> cantidad >> querys;

    ft.resize((cantidad + 5) * 3);
    copia.resize(cantidad);
    copia2.resize(cantidad + 1);

    for (int i = 1; i <= cantidad; i++)
    {
        cin >> copia[i - 1];
        copia2[i] = copia[i - 1];
    }

    while (querys--)
    {

        cin >> car >> a >> b;

        qqq.push_back({car, {a, b}});

        if(car == '!') copia.push_back(b);
        else{
            copia.push_back(a - 1);
            copia.push_back(b);
        }
    }

    sort(copia.begin(), copia.end());

    for (auto i : copia)
    {
        if (mapa[i] == 0)
        {   
            //cout << i << " ---> ";
            //cout << e << "\n";
            mapa[i] = e;
            e++;
        }
    }
    //cout << "\n";

    for (int i = 1; i <= cantidad; i++)
    {
        update(mapa[copia2[i]], 1);
    }

    for (auto i : qqq)
    {
        car = i.first;
        a = i.second.first;
        b = i.second.second;

        if (car == '?')
            cout << query(mapa[b]) - query(mapa[a - 1]) << "\n";
        else
        {
            update(mapa[copia2[a]], -1);
            copia2[a] = b;
            update(mapa[b], 1);
        }
    }

    return 0;
}