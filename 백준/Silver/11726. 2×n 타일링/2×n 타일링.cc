#include<iostream>
#include<vector>
using namespace std;

vector<long long> dp;
int n;

// 2xn 타일링 #11726
int main(){
    cin >> n;

    dp = vector<long long>(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    cout << dp[n];

    return 0;
}