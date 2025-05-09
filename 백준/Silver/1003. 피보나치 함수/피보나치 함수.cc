#include<iostream>
#include<vector>
using namespace std;

// 피보나치 함수 #1003

int t,n;

vector<long long> zeroDP(41);
vector<long long> oneDP(41);



void fibonacci(int n){
    for (int i = 2; i <= n; i++)
    {
        zeroDP[i] = zeroDP[i-1] + zeroDP[i-2];
        oneDP[i] = oneDP[i-1] + oneDP[i-2];
    }
}

int main(){
    zeroDP[0] = 1;
    zeroDP[1] = 0;
    oneDP[0] = 0;
    oneDP[1] = 1;

    cin >> t;
    while(t--){
        cin >> n;
        fibonacci(n);
        cout << zeroDP[n] << " " << oneDP[n] << "\n";
    }

    return 0;
}