#include <bits/stdc++.h>

using namespace std;

int toBinary(string s){
    int sum = 0;
    for(int i = s.size() - 1; i >= 0; i --){
        sum += pow(2, ((int)s.size() - i - 1)) * (s[i] - '0');
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*
    10 -> 2
    11 -> 3
    100 -> 4
    */
    string n;
    bool tengo = false;

    cin >> n;

    for(int i = 0; i < (int)n.size(); i ++){
        if(n[i] == '0'){
            if(tengo){
                n[i] = '1';
            }
        }
        else if(n[i] != '1'){
            tengo = true;
            n[i] = '1';
        }
    }

    cout << toBinary(n);
    return 0;
}