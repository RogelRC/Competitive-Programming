#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > matriz;
vector<int> visitado;
queue<int> cola;

int main()
{

    int nodos, aristas, e1, e2, flag;

    while(cin >> nodos && nodos != 0){
        cin >> aristas;

        matriz.clear();
        visitado.clear();
        matriz.resize(nodos);
        visitado.resize(nodos);
        fill(visitado.begin(), visitado.end(), -1);
        visitado[0] = 1;
        flag = true;

        while(aristas --){
            cin >> e1 >> e2;

            matriz[e1].push_back(e2);
            matriz[e2].push_back(e1);
        }

        cola.push(0);

        while(!cola.empty()){
            int actual = cola.front();
            cola.pop();

            for(int i = 0; i < matriz[actual].size(); i ++){
                int ady = matriz[actual][i];

                if(visitado[ady] == -1){
                    visitado[ady] = (visitado[actual] + 1) % 2;

                    cola.push(ady);
                }
                else if(visitado[ady] == visitado[actual]) flag = false;
            }
        }

        if(flag == true) cout << "BICOLORABLE\n";
        else cout << "NOT BICOLORABLE\n";


    }

    return 0;
}
