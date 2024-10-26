#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int D, F;

    cin >> F >> D;

    vector<pair<int, int> > dragones(D);

    for(int i = 0; i < D; i ++){
        cin >> dragones[i].first >> dragones[i].second;
    }

    sort(dragones.begin(), dragones.end());

    for(int i = 0; i < D; i ++){
        if(F > dragones[i].first){
            F += dragones[i].second;
        }
        else{
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}