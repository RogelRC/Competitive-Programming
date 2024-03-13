#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(const pair<long long, long long> &a, const pair<long long, long long> &b){
        if(a.first != b.first) return a.first > b.first;

        return a.second < b.second;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long casos, participantes, problemas, duracion, puntos, penalty, tiempo, sol;
    vector<vector<long long> > matriz;
    vector<pair<long long, long long> > resultados;

    cin >> casos;

    while(casos --){
        cin >> participantes >> problemas >> duracion;

        matriz.resize(participantes);
        resultados.resize(participantes);
        sol = 1;

        for(long long i = 0; i < participantes; i ++){
            matriz[i].resize(problemas);

            for(long long j = 0; j < problemas; j ++){
                cin >> matriz[i][j];
            }

            sort(matriz[i].begin(), matriz[i].end());

            puntos = 0;
            penalty = 0;
            tiempo = 0;

            for(long long j = 0; j < problemas; j ++){
                if(tiempo + matriz[i][j] <= duracion){
                    tiempo += matriz[i][j];
                    puntos ++;
                    penalty += tiempo;
                }
                else break;
            }

            resultados[i] = make_pair(puntos, penalty);
        }

        for(long long i = 1; i < participantes; i ++){
            if(resultados[i].first > resultados[0].first) sol ++;
            else if(resultados[i].first == resultados[0].first && resultados[i].second < resultados[0].second) sol ++;
        }

        cout << sol << "\n";
    }

    return 0;
}