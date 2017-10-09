#include <iostream>
#include <numeric>

using namespace std;

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{
    int N, L, aux;
    int maior = 0;
    int resp = 0;
    int MMC = 1;
    int X;

    cin >> N >> L;

    int arr[N+1];

    for(int i=0;i<N;i++){
        cin >> arr[i];
        MMC = lcm(arr[i], MMC);
    }
    //cout << MMC << endl;

    X = L - ( L % MMC);

    for(int i=1;i<=L;i++){
        aux = lcm(MMC,i);
        if (aux <= L && aux > maior && aux % X == 0){
            maior = aux;
            resp = i;
        }
    }


    cout << resp << endl;
}
