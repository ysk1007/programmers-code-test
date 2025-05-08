#include<iostream>
#include<vector>
using namespace std;

// 파도반 수열 #9461

vector<long long> vc(101);
int t,n;

int main(){
    vc[1] = 1;
    vc[2] = 1;
    vc[3] = 1;

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 4 ; i <= n ; i++){
            vc[i] = vc[i-2] + vc[i-3];
        }
        cout << vc[n] << "\n";
    }

    return 0;
}