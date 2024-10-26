#include <bits/stdc++.h>

using namespace std;

long long n, m, e1, e2, p;

const long long MaxN = 2505;

long long recorrido[MaxN];
bool vrec[MaxN];

struct Edge
{
    long long src, dst, weight;
    Edge(long long a, long long b, long long c) : src(a), dst(b), weight(c) {}
};

vector<Edge> edges;
vector<long long> dist;
vector<long long> sol;

void r(long long p){
    //cout << p << " ";
    if(vrec[p] == true){
        sol.push_back(p);
        return;
    }
    vrec[p] = true;

    r(recorrido[p]);
    sol.push_back(p);
}

bool Bellman_Ford(long long s)
{
    dist = vector<long long>(n + 1, INT64_MAX / 2);
    dist[s] = 0;

    for (long long i = 0; i < n - 1; ++i)
    {
        for (auto e : edges)
        {
            long long u = e.src;
            long long v = e.dst;
            long long w = e.weight;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                //cout << v << " " << u << "\n";
                recorrido[v] = u;
            }
        }
    }

    for (auto e :edges)
    {
        long long u = e.src;
        long long v = e.dst;
        long long w = e.weight;

        //cout << u << " " << v << "\n";

        if (dist[u] + w < dist[v]){
            //cout << "Enc: " << u << " " << v << "\n";
            recorrido[v] = u;
            r(u);
            return false; // negative_cycle_exist
        }
    }
    return true;
}

int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(recorrido, -1, sizeof(recorrido));

    cin >> n >> m;

    for (long long i = 0; i < m; i++)
    {
        cin >> e1 >> e2 >> p;

        edges.push_back({e1, e2, p});
    }

    if(Bellman_Ford(n) == false){
        cout << "YES\n";

        cout << sol[0] << " ";

        for(int i = 1; i < sol.size(); i ++){
            cout << sol[i] << " ";
            if(sol[i] == sol[0]) break;
        }
    }
    else cout << "NO\n";

    return 0;
}