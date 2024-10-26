    #include <bits/stdc++.h>

    using namespace std;

    #define NMAX 200005

    #define min max

    bool updated;
    int cantidad, querys, a, b, c;
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

    int pos, val;
    void update(int p, int a, int b){
        if(a == b){
            return;
        }
        int mid = (a + b) / 2;
        if(pos <= mid){
            update(p * 2, a, mid);
        }
        else{
            update(p * 2 + 1, mid + 1, b);
        }
        tree[p] = min(tree[p * 2], tree[p * 2 + 1]);
        return;
    }

    int fff;
    int solve(int p, int a, int b){
        if(tree[p] < fff) return 0;
        if(b == a){
            if(tree[p] < fff){
                pos = 0;
                return 0;
            }

            int sol = tree[p];
            pos = a;
            if(updated == false){
                tree[p] -= fff;
                //cout << "l";
                updated = true;
                update(1, 1, cantidad);
            }
            return sol;
        }

        int mid = (a + b) / 2;

        int aaa = solve(p * 2, a, mid);
        int bbb;

        if(aaa >= fff) return aaa;

        bbb = solve(p * 2 + 1, mid + 1, b);
        if(bbb >= fff) return bbb;
        else return 0;
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
            updated = false;
            cin >> fff;

            if(fff <= tree[1]){
                solve(1, 1, cantidad);

                cout << pos << " ";
            }
            else cout << 0 << " ";

        }


        return 0;
    }