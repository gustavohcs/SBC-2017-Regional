#include <iostream>
#include <set>

using namespace std;

int main(){

    int N;
    int X;

    set<int> guarda[13];

    for(int k=1;k<=12;k++){
        guarda[k].insert(k%12);
        guarda[k].insert((k+2)%12);
        guarda[k].insert((k+4)%12);
        guarda[k].insert((k+5)%12);
        guarda[k].insert((k+7)%12);
        guarda[k].insert((k+9)%12);
        guarda[k].insert((k+11)%12);
    }

    cin >> N;

    int arr[N+1];

    for(int i=0;i<N;i++){
        cin >> X;
        arr[i] = X%12;
    }

    bool passou;
    int aux = 99;

    for(int j=1;j<=12;j++){
        passou = true;
        for(int i=0;i<N;i++){
            if (guarda[j].count(arr[i]) > 0){
                continue;
            }
            else{
                passou = false;
                break;
            }
        }
        if (passou == true){
            aux = j;
            break;
        }
    }

    if (aux==1) cout << "do" << endl;
    if (aux==2) cout << "do#" << endl;
    if (aux==3) cout << "re" << endl;
    if (aux==4) cout << "re#" << endl;
    if (aux==5) cout << "mi" << endl;
    if (aux==6) cout << "fa" << endl;
    if (aux==7) cout << "fa#" << endl;
    if (aux==8) cout << "sol" << endl;
    if (aux==9) cout << "sol#" << endl;
    if (aux==10) cout << "la" << endl;
    if (aux==11) cout << "la#" << endl;
    if (aux==12) cout << "si" << endl;

    if (aux==99) cout << "desafinado" << endl;







return 0;
}
