#include <iostream>
#include <vector>

typedef long long int ll;

using namespace std;

int main(){

    ll T, Min, Max, aux;

    ll cont =0;

    cin >> T >> Min >> Max;

    aux = Max-Min+1;

    //unsigned mat[T+1][aux+1];
    //vector <int> mat[T+2];
    //vector< vector<int> > mat(aux, vector<int>(T+1));
    vector<vector <ll> > mat(T+1, vector<ll> (100001));

    for(ll j=1;j<=T;j++){
        for(ll i=1;i<=aux;i++){
            mat[j][i] = 0;
        }
    }

    for(ll i=1;i<=aux;i++)
        mat[1][i] = 1;

    for(ll j=1;j<T;j++){
        for(ll i=1;i<=aux;i++){
            if (i-1 > 0){
                mat[j+1][i-1] += mat[j][i]%1000000007;
            }
            if (i+1 <= aux){
                mat[j+1][i+1] += mat[j][i]%1000000007;
            }
        }
    }



   // for(int j=1;j<=T;j++){
    //        cout << endl;
    //    for(int i=1;i<=aux;i++){
    //        cout << mat[j][i] << " ";
    //    }
    //}
    cont=0;
    for(ll i=1;i<=aux;i++){
        cont+=mat[T][i];
        //cout << mat[T][i] << endl;
    }

    cout << cont%1000000007 << endl;

return 0;
}
