#include <iostream>
 
using namespace std;
 
int main() {
 
    string texto = "";
    
    cin >> texto;
    
    int X = 0;
    
    for(int i=0;i<texto.size();i++){
        X+=(texto[i]-'0');
    }
    
    cout << X%3 << endl;
 
    return 0;
}
