#include <bits/stdc++.h>

using namespace std;

bool check(string s){
    for(int i = 0, j = s.size() - 1; i <= j; i ++, j --){
        if(s[i] != s[j]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int casos, ceros, unos, t0 = 0, t1 = 0;
    bool flag;
    string cadena;

    cin >> casos;

    while(casos --){
        flag = true;
        t0 = 0, t1 = 0;

        cin >> ceros >> unos >> cadena;

        for(int i = 0; i < cadena.size(); i ++){
            if(cadena[i] == '0') t0 ++;
            else if(cadena[i] == '1') t1 ++;
        }

        ceros -= t0;
        unos -= t1;

        for(int i = 0; i < cadena.size() / 2; i ++){
            if(cadena[i] == '?'){
                if(cadena[cadena.size() - i - 1] == '0'){
                    cadena[i] = '0';
                    ceros --;
                }
                else if(cadena[cadena.size() - i - 1] == '1'){
                    cadena[i] = '1';
                    unos--;
                }
            }
            else if(cadena[cadena.size() - i - 1] == '?'){
                if(cadena[i] == '0'){
                    cadena[cadena.size() - i - 1] = '0';
                    ceros --;
                }
                else if(cadena[i] == '1'){
                    cadena[cadena.size() - i - 1] = '1';
                    unos--;
                }
            }

            if(ceros < 0 || unos < 0) flag = false;
        }

        //cout << flag << " " << ceros << " " << unos << " ";
        if(flag == true){
            for(int i = 0, j = cadena.size() - 1; i <= j; i ++, j --){
                if(cadena[i] == '?'){
                    if(i == j){
                        if(ceros >= 1){
                            ceros --;
                            cadena[i] = '0';
                        }
                        else if(unos >= 1){
                            unos --;
                            cadena[i] = '1';
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                    else{
                        if(ceros >= 2){
                            ceros -= 2;
                            cadena[i] = cadena[j] = '0';
                        }
                        else if(unos >= 2){
                            unos -= 2;
                            cadena[i] = cadena[j] = '1';
                        }
                        else{
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }

        if(flag == true && check(cadena) == true && ceros == 0 && unos == 0) cout << cadena << "\n";
        else cout << "-1\n";
    }

    return 0;
}