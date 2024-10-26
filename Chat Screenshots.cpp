#include <bits/stdc++.h>

using namespace std;

int casos, nodos, k, a, ant;
vector<vector<int> > matriz;
vector<bool> visitado;
vector<bool> recStack;

bool tieneCiclo(int node) {
    if(!visitado[node]) {
        visitado[node] = true;
        recStack[node] = true;

        for(int v: matriz[node]) {
            if(!visitado[v] && tieneCiclo(v))
                return true;
            else if(recStack[v])
                return true;
        }
    }
    recStack[node] = false;
    return false;
}

bool sol() {
    for(int i = 1; i <= nodos; i++) {
        if(tieneCiclo(i))
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> casos;

    while(casos --){
        cin >> nodos >> k;

        matriz.clear();
        matriz.resize(nodos + 1);
        visitado.clear();
        visitado.resize(nodos + 1, false);
        recStack.clear();
        recStack.resize(nodos + 1, false);

        while(k --){
            ant = -1;

            cin >> a;

            for(int i = 0; i < nodos - 1; i ++){
                cin >> a;

                if(ant != -1){
                    matriz[ant].push_back(a);
                }

                ant = a;
            }
        }

        if (sol()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
