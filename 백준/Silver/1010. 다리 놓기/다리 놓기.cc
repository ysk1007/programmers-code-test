#include<iostream>

using namespace std;

// 다리 놓기 #1010
int main(){
    int t,n,m;
    cin >> t;

    long long dp[30][30] = {0};

    for(int i = 1 ; i <= 30 ; i++){
        dp[1][i] = i;
        for(int j = 2 ; j < i ; j++){
            dp[j][i] = dp[j-1][i-1] + dp[j][i-1];
        }
        dp[i][i] = 1;
    }


    while(t--){
        cin >> n >> m;

        cout << dp[n][m] << "\n";
    }

    

    return 0;
}