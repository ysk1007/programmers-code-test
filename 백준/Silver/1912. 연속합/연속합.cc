#include<iostream>

using namespace std;

// 연속합 #1912
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int num[t];
    int dp[t+1] = {0};

    for(int i = 0 ; i < t ; i++){
        cin >> num[i];
    }

    dp[0] = num[0];
    int result = dp[0];

    for(int i = 1 ; i < t ; i++){
        int n = num[i];


        // 시나리오 2가지
        // s1. 이전 dp 에서 본인까지 합한게 높다
        // s2. 이전 dp 보다 본인이 높음

        int sum = max(n,dp[i-1]+n);

        dp[i] = sum;
        result = max(sum,result);
    }

    // 디버깅
    // for(int i = 0 ; i < t ; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << "\n";

    cout << result;
    return 0;
}