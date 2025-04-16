#include<iostream>

using namespace std;

// 상근이의 친구들 #5717
int main(){
    int m,f;

    while(true){
        cin >> m >> f;
        if(m == 0 && f == 0) break;
        cout << m + f << "\n";
    }

    return 0;
}