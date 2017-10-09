#include <iostream>

using namespace std;

int main(){

    int A1, A2, A3, aux1, aux2, aux3, aux;

    cin >> A1 >> A2 >> A3;

    aux1 = A2*2 + A3*4;
    aux2 = A1*2 + A3*2;
    aux3 = A1*4 + A2*2;


    cout << min(min(aux1,aux2),aux3) << endl;



return 0;
}
