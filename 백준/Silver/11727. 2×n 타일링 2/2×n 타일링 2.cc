#include<iostream>
#include<vector>
using namespace std;

// 2xn타일링 2 #11727

int n;
vector<long long> dp;
int main(){
    cin >> n;

    dp = vector<long long>(n + 1);

    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3 ; i <= n ; i++){
        dp[i] = (dp[i-2] * 2 + dp[i-1]) % 10007;
    }

    cout << dp[n];

    return 0;
}