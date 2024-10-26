#include <bits/stdc++.h>

using namespace std;

#define NMAX 100005

vector<int> matriz[NMAX];
int visitado[NMAX];
int trip[NMAX];
int nodos, aristas, e1, e2;
bool stopflag = false;
vector<int> sol;

void printTrip(int actual, int &inicio){
    sol.push_back(actual);

    if(actual == inicio) return;

    printTrip(trip[actual], inicio);
}

void dfs(int actual, int anterior){
    if(stopflag == true) return;

    visitado[actual] = true;

    for(int &i: matriz[actual]){
        if(stopflag == true) return;

        if(i == anterior) continue;

        trip[i] = actual;

        if(visitado[i] == true){
            stopflag = true;

            sol.push_back(i);

            printTrip(actual, i);
        }

        dfs(i, actual);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nodos >> aristas;

    while(aristas --){
        cin >> e1 >> e2;

        matriz[e1].push_back(e2);
        matriz[e2].push_back(e1);
    }

    for(int i = 1; i <= nodos && stopflag == false; i ++){
        if(visitado[i] == false){
            dfs(i, 0);
        }
    }

    if(sol.empty() == false){
        cout << sol.size() << "\n";

        for(int i: sol){
            cout << i << " ";
        }
    }
    else cout << "IMPOSSIBLE";

    return 0;
}