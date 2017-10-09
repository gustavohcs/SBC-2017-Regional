#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int N, L, cont=0;

    cin >> N >> L;

    int arr[N+1];

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    sort(arr,arr+N);

    int i=N-1;

    while(L>0){
        cont++;
        i--;
        L--;
    }

    int k=0;
    while (arr[i+1-k]==arr[i-k]){
        k++;
        cont++;
    }

        cout << cont << endl;

return 0;
}
