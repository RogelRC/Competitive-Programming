#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, r, p, s, rr, pp, ss, ganadas, rrr, ppp, sss;
    string cadena;
    vector<char> sol;

    cin >> casos;

    while(casos --){
        cin >> r >> r >> p >> s >> cadena;

        sol.resize(cadena.size());
        fill(sol.begin(), sol.end(), ' ');

        rr = 0;
        pp = 0;
        ss = 0;

        for(int i = 0; i < cadena.size(); i ++){
            if(cadena[i] == 'R') rr ++;
            else if(cadena[i] == 'P') pp ++;
            else if(cadena[i] == 'S') ss ++;
        }

        rrr = min(r, ss);
        ppp = min(p, rr);
        sss = min(s, pp);

        ganadas = rrr + ppp + sss;

        if(ganadas >= (cadena.size() + 1) / 2){
            cout << "YES\n";

            for(int i = 0; i < cadena.size(); i ++){
                if(cadena[i] == 'R' && p > 0){
                    sol[i] = 'P';
                    p --;
                }
                else if(cadena[i] == 'P' && s > 0){
                    sol[i] = 'S';
                    s --;
                }
                else if(cadena[i] == 'S' && r > 0){
                    sol[i] = 'R';
                    r --;
                }
            }

            for(int i = 0; i < sol.size(); i ++){
                if(sol[i] == ' '){
                    if(r > 0) sol[i] = 'R', r --;
                    else if(p > 0) sol[i] = 'P', p --;
                    else if(s > 0) sol[i] = 'S', s --;

                }
                cout << sol[i];
            }
            cout << "\n";
        }
        else cout << "NO\n";
    }

    return 0;
}