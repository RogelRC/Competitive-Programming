#include <bits/stdc++.h>

using namespace std;

int llegar;
string s1, s2;

int dina(int p, int sum){
    if(p == s2.size()){
        if(sum == llegar) return 1;
        else return 0;
    }

    if(s2[p] == '-') return dina(p + 1, sum - 1);
    else if(s2[p] == '+') return dina(p + 1, sum + 1);
    else return dina(p + 1, sum - 1) + dina(p + 1, sum + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int total = 1;

    cin >> s1 >> s2;

    for(int i = 0; i < s1.size(); i ++){
        if(s1[i] == '-') llegar --;
        else llegar ++;
    }

    for(int i = 0; i < s2.size(); i ++){
        if(s2[i] == '?') total *= 2;
    }

    cout << fixed << setprecision(12) << (double)dina(0, 0) / (double)total;

    return 0;
}