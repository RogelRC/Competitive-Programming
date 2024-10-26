#include <bits/stdc++.h>

using namespace std;

#define MaxN 1005
int N, Q;
int ft[MaxN][MaxN];
int matriz[MaxN][MaxN];

int lowbit(int x) { return x & -x; }

bool Valid(int r, int c)
{
    if (r < 1 || r > N)
        return false;
    if (c < 1 || c > N)
        return false;
    return true;
}
void update(int r, int c, int val)
{
    if (!Valid(r, c))
        return;
    for (int i = r; i <= N; i += lowbit(i))
        for (int j = c; j <= N; j += lowbit(j))
            ft[i][j] += val;
}

int query(int r, int c)
{
    if (!Valid(r, c))
        return 0;
    int sum = 0;
    for (int i = r; i > 0; i -= lowbit(i))
        for (int j = c; j > 0; j -= lowbit(j))
            sum += ft[i][j];
    return sum;
}
int query(int r, int c, int R, int C)
{
    return query(R, C) - query(R, c - 1) - query(r - 1, C) + query(r - 1, c - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d, q;
    char ss;

    cin >> N >> Q;

    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= N; j ++){
            cin >> ss;
            if(ss == '*'){
                update(i, j, 1);
                matriz[i][j] = 1;
            }
            else{
                matriz[i][j] = 0;
            }
        }
    }

    while(Q --){
        cin >> q;

        if(q == 2){
            cin >> a >> b >> c >> d;

            cout << query(c, d) - query(c, b - 1) - query(a - 1, d) + query(a - 1, b - 1) << "\n";
        }
        else{
            cin >> a >> b;

            if(matriz[a][b] == 1){
                matriz[a][b] = 0;
                update(a, b, -1);
            }
            else{
                matriz[a][b] = 1;
                update(a, b, 1);
            }
        }
    }
}
