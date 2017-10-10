#include<iostream>
#include <vector>
typedef long long int ll;

using namespace std;

vector<vector <int> > adj(10001, vector<int> (10001));
vector<vector <int> > peso(10001, vector<int> (10001));
vector<int> ouro(10001);
vector<int> visitado(10001);
//ll ouro[10010];
//ll visitado[10010]; // vetor de visitação
//ll adj[10010][10010]; // matriz de adjacencia
//ll peso[10010][10010]; // matriz de adjacencia
ll km = 0;
ll viagens;

void dfs(int u, int N, int last, int carga) {
    //cout << u << ' ' << last << endl;
    if (visitado[u])
        return;
    for (int v=1; v <= N; v++){
            //cout << "1111111111111" << endl;
        if (v==last)
            v++;
        if (v>N) break;
        if (adj[u][v]) {
            //cout << "2222222222222" << endl;
            adj[v][u] = 0;
            dfs(v,N,u,carga);
        }
    }

    if (last != u){
        if (ouro[u]%carga==0)
            viagens = 2*((ouro[u]/carga));
        else
            viagens = 2*((ouro[u]/carga) + 1);
        km+=viagens*(peso[u][last]);
        ouro[last] += ouro[u];
        ouro[u] = 0;
    }
    if (ouro[u] == 0)
        visitado[u] = 1;
    //cout << "VISITOU " << u << " ouro last: " << last << " " << ouro[last] << " km: " << km << endl;

    return;
}


int main()
{

    int N, C, aux;

    //std::ios::sync_with_stdio(false);

    cin >> N >> C;

    //for(ll j=1;j<=N;j++){
    //    for(ll i=1;i<=N;i++){
    //        adj[j][i] = 0;
     //       peso[j][i] = 0;
    //    }
    //}

    for (int i=1; i <= N; i++){
        visitado[i] = 0;
        ouro[i] = 0;
        cin >> aux;
        ouro[i] = aux;
    }

    int X, Y, dist;

    for(int i=1;i<N;i++){
        cin >> X >> Y >> dist;
        adj[X][Y] = 1;
        adj[Y][X] = 1;
        peso[X][Y] = dist;
        peso[Y][X] = dist;
    }

    dfs(1,N,1,C);

    //cout << ouro[1] << endl;
    cout << km << endl;


    return 0;
}
