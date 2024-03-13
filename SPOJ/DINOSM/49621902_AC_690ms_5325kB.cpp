#include <bits/stdc++.h>

using namespace std;

long long D;
double W, H;

struct datos{
    double distancia;
    long long e1, e2;
};

struct cmp{
    bool operator()(const datos &a, const datos &b){
        return a.distancia < b.distancia;
    }
};

vector<datos> matriz;
pair<double, double> dinos[305];
long long padre[305];

double distancia(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

long long getPadre(long long n){
    if(padre[n] == n) return n;
    return padre[n] = getPadre(padre[n]);
}

void unir(long long a, long long b){
    a = getPadre(a);
    b = getPadre(b);

    if(a == b) return;
    padre[b] = a;
}

/*
0 = abajo
1 = arriba
2 = izquierda
3 = derecha
*/

void build(){
    for(long long i = 0; i < D; i ++){
        for(long long j = i + 1; j < D; j ++){
            matriz.push_back({(double)0.5 * distancia(dinos[i].first, dinos[i].second, dinos[j].first, dinos[j].second), i + 4, j + 4});
        }

        //abajo
        matriz.push_back({dinos[i].second, 0, i + 4});

        //arriba
        matriz.push_back({H - dinos[i].second, 1, i + 4});

        //izquierda
        matriz.push_back({dinos[i].first, 2, i + 4});

        //derecha
        matriz.push_back({W - dinos[i].first, 3, i + 4});
    }
}

bool check(){
    long long p0 = getPadre(0);
    long long p1 = getPadre(1);
    long long p2 = getPadre(2);
    long long p3 = getPadre(3);

    return p0 == p1 || p0 == p2 || p1 == p3 || p2 == p3;
}

double solve(){
    double solucion = INT_MIN;
    long long a, b;

    matriz.clear();
    for(long long i = 0; i < D + 4; i ++){
        padre[i] = i;
    }

    for(long long i = 0; i < D; i ++){
        cin >> dinos[i].first >> dinos[i].second;
    }

    build();

    sort(matriz.begin(), matriz.end(), cmp());

    for(long long i = 0; i < (long long)matriz.size(); i ++){
        //cout << matriz[i].distancia << "\n";

        a = getPadre(matriz[i].e1);
        b = getPadre(matriz[i].e2);

        if(a != b){
            unir(a, b);

            solucion = max(solucion, matriz[i].distancia);

            if(check()) return solucion;
        }
    }

    return solucion;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> D >> W >> H && D != -1 && W != -1 && H != -1){
        cout << fixed << setprecision(3) << solve() << "\n";
    }

    return 0;
}