#include<iostream>
#include<vector>
using namespace std;

// 1,2,3 더하기 #9095

vector<int> dp(11);
int t,n;

int main(){
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 4 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[n] << "\n";
    }

    return 0;
}