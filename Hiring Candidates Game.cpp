#include <bits/stdc++.h>

using namespace std;

int cantidad, a, b, c, aaa, bbb, ca, cb;
vector<int> lista, hired;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> cantidad >> a >> b;

    c = cantidad;
    ca = a;
    cb = b;
    aaa = 1;
    bbb = cantidad;

    for(int i = 0; i <= cantidad; i ++){
        lista.push_back(i);
    }

    while(c > 2){
        
        /*
        for(int i = 1; i <= cantidad; i ++){
            cout << lista[i] << " ";
        }
        cout << "\n";
        */

        a = (ca) % c;
        b = (cb) % c;

        if(a == 0) a = c;
        if(b == 0) b = c;

        if(a == 0){
            for(int i = aaa;; i ++){
                if(i == cantidad + 1) i = 1;

                aaa = i;

                if(lista[i] != 0) break;
            }
        }

        if(b == 0){
            for(int i = bbb;; i --){
                if(i == 0) i = cantidad;

                bbb = i;

                if(lista[i] != 0) break;
            }
        }

        for(int i = aaa, found = 0; found < a; i ++){
            if(i == cantidad + 1) i = 1;

            if(lista[i] != 0) found ++;

            aaa = i;
        }

        for(int i = bbb, found = 0; found < b; i --){
            if(i == 0) i = cantidad;

            if(lista[i] != 0) found ++;

            bbb = i;
        }


        if(aaa == bbb){
            hired.push_back(lista[aaa]);
            lista[aaa] = 0;

            c --;
        }
        else{
            lista[aaa] = lista[bbb] = 0;

            c -= 2;
        }

        aaa ++;
        if(aaa == cantidad + 1) aaa = 1;

        bbb --;
        if(bbb == 0) bbb = cantidad;
    }


    for(int i = 1; i <= cantidad; i ++){
        //cout << lista[i] << " ";

        if(lista[i] != 0) hired.push_back(lista[i]);
    }

    //cout << "\n";

    sort(hired.begin(), hired.end());

    for(int i = 0; i < hired.size(); i ++){
        cout << hired[i] << " ";
    }

    return 0;
}