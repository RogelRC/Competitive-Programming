#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

vector<vector<pair<int, int> > > matriz;
vector<int> distanciac;
vector<int> distancian;
vector<int> distanciabar;
vector<bool> visitado;
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> cola;

int main(){

    int nodos, bar, carlitos, nene, aristas, sc, sn, tt, e1, e2, p;

    while(1){
        cin >> nodos >> bar >> carlitos >> nene >> aristas;

        if(nodos == -1 && bar == -1 && carlitos == -1 && nene == -1 && aristas == -1) break;

        matriz.clear();
        distanciac.clear();
        distancian.clear();
        distanciabar.clear();
        visitado.clear();

        matriz.resize(nodos + 1);
        distanciac.resize(nodos + 1);
        distancian.resize(nodos + 1);
        distanciabar.resize(nodos + 1);
        visitado.resize(nodos + 1);

        fill(distanciac.begin(), distanciac.end(), INT_MAX);
        fill(distancian.begin(), distancian.end(), INT_MAX);
        fill(distanciabar.begin(), distanciabar.end(), INT_MAX);
        fill(visitado.begin(), visitado.end(), false);

        tt = 0;

        for(int i = 0; i < aristas; i ++){
            cin >> e1 >> e2 >> p;

            matriz[e1].push_back(make_pair(e2, p));
            matriz[e2].push_back(make_pair(e1, p));
        }

        distanciac[carlitos] = 0;
        cola.push(make_pair(carlitos, 0));

        while(!cola.empty()){
            int actual = cola.top().first;
            cola.pop();

            if(visitado[actual] == true) continue;
            visitado[actual] = true;

            for(int i = 0; i < matriz[actual].size(); i ++){
                int ady = matriz[actual][i].first;

                if(distanciac[actual] + matriz[actual][i].second < distanciac[ady]){
                    distanciac[ady] = distanciac[actual] + matriz[actual][i].second;

                    cola.push(make_pair(ady, distanciac[ady]));
                }
            }
        }

        fill(visitado.begin(), visitado.end(), false);

        distancian[nene] = 0;
        cola.push(make_pair(nene, 0));

        while(!cola.empty()){
            int actual = cola.top().first;
            cola.pop();

            if(visitado[actual] == true) continue;
            visitado[actual] = true;

            for(int i = 0; i < matriz[actual].size(); i ++){
                int ady = matriz[actual][i].first;

                if(distancian[actual] + matriz[actual][i].second < distancian[ady]){
                    distancian[ady] = distancian[actual] + matriz[actual][i].second;

                    cola.push(make_pair(ady, distancian[ady]));
                }
            }
        }

        fill(visitado.begin(), visitado.end(), false);

        distanciabar[bar] = 0;
        cola.push(make_pair(bar, 0));

        while(!cola.empty()){
            int actual = cola.top().first;
            cola.pop();

            if(visitado[actual] == true) continue;
            visitado[actual] = true;

            for(int i = 0; i < matriz[actual].size(); i ++){
                int ady = matriz[actual][i].first;

                if(distanciabar[actual] + matriz[actual][i].second < distanciabar[ady]){
                    distanciabar[ady] = distanciabar[actual] + matriz[actual][i].second;

                    cola.push(make_pair(ady, distanciabar[ady]));
                }
            }
        }

        sc = distanciac[bar];
        sn = distancian[bar];

        for(int i = 1; i <= nodos; i ++){

            if(distanciac[i] + distanciabar[i] == distanciac[bar] && distancian[i] + distanciabar[i] == distancian[bar]){
                if(tt < distanciabar[i]){
                    tt = distanciabar[i];
                    sc = distanciac[i];
                    sn = distancian[i];
                }
            }
        }

        cout << tt << " " << sc << " " << sn << "\n";


    }

    //cin >> nodos;

    return 0;
}
