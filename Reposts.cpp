#include <bits/stdc++.h>

using namespace std;

void cosa(string &s){
    for(int i = 0; i < s.size(); i ++){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int nodos, sol = 2;
    string e1, e2;
    map<string, vector<string> > matriz;
    map<string, int> visitado;
    queue<string> cola;

    cin >> nodos;

    while(nodos --){
        cin >> e1 >> e2 >> e2;

        cosa(e1);
        cosa(e2);

        matriz[e2].push_back(e1);
    }

    visitado["polycarp"] = 1;
    cola.push("polycarp");

    while(!cola.empty()){
        string actual = cola.front();
        cola.pop();

        for(auto i : matriz[actual]){
            if(visitado[i] == 0){
                visitado[i] = visitado[actual] + 1;
                cola.push(i);
            }
        }
    }

    for(auto i: matriz){
        sol = max(sol, visitado[i.first]);
    }

    cout << sol;

    return 0;
}