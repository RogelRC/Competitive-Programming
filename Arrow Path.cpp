    #include <bits/stdc++.h>

    #define mt(a, b, c) make_pair(a, make_pair(b, c))

    using namespace std;

    int casos, n;

    char matriz[3][200005];
    bool visitado[2][3][200005];
    int adyx[4] = {0, 0, 1, -1};
    int adyy[4] = {-1, 1, 0, 0};
    queue<pair<bool, pair<int, int> > > cola;

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        cin >> casos;

        while(casos --){
            cin >> n;

            for(int i = 1; i <= 2; i ++){
                for(int j = 1; j <= n; j ++){
                    cin >> matriz[i][j];
                }
            }

            cola.push(mt(false, 1, 1));
            visitado[1][1][1] = true;

            while(!cola.empty()){
                bool a = cola.front().first;
                int x = cola.front().second.first;
                int y = cola.front().second.second;

                cola.pop();

                if(x == 2 && y == n) break;

                if(a == false){
                    for(int i = 0; i < 4; i ++){
                        int xx = x + adyx[i];
                        int yy = y + adyy[i];

                        if(xx >= 1 && xx <= 2 && yy >= 1 && yy <= n && visitado[true][xx][yy] == false){
                            visitado[true][xx][yy] = true;

                            cola.push(mt(true, xx, yy));
                        }
                    }
                }
                else{
                    if(matriz[x][y] == '<' && visitado[false][x][y - 1] == false){
                        cola.push(mt(false, x, y - 1));
                        visitado[false][x][y - 1] = true;
                    }
                    else if(matriz[x][y] == '>' && visitado[false][x][y + 1] == false){
                        cola.push(mt(false, x, y + 1));
                        visitado[false][x][y + 1] = true;
                    }
                }
            }

            if(visitado[false][2][n] == true || visitado[true][2][n] == true) cout << "YES\n";
            else cout << "NO\n";

            while(!cola.empty()) cola.pop();
            for(int i = 1; i <= 2; i ++){
                for(int j = 1; j <= n; j ++){
                    visitado[false][i][j] = visitado[true][i][j] = false;
                }
            }

        }

        return 0;
    }