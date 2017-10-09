#include <iostream>
#include <set>
#include <math.h>

using namespace std;

typedef long long int ll;

set<ll> primos_distintos_da_fatoracao(ll n) {
    set<ll> primos_distintos;
    while (n % 2 == 0) {
         primos_distintos.insert(2);
         n /= 2;
    }

    for (ll i = 3; n != 1 && i <= sqrt(n); i += 2) {
         while (n % i == 0) {
             primos_distintos.insert(i);
             n /= i;
          }
    }

    if (n > 1) primos_distintos.insert(n);

    return primos_distintos;
}

int main(){

    ll N, resp;

    cin >> N;

    set<ll> conjunto = primos_distintos_da_fatoracao(N);

    resp = pow(2, conjunto.size()) - conjunto.size() - 1;

    cout << resp << endl;

    return 0;

}
