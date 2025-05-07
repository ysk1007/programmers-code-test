#include<iostream>
#include<vector>
using namespace std;

// 1로 만들기 #1463
int main(){
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[1] = 0;  // 1 -> 0
    dp[2] = 1;  // 2(2-1) -> 1
    dp[3] = 1;  // 3(3/3) -> 1

    for(int i = 4 ; i <= n ; i++){

        // 3가지 경우의 수를 비교해서 가장 작은 수를 찾자

        dp[i] = dp[i-1] + 1;    // 1. 이전 수에서 -1 한 횟수
        if(i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);   // 2. 3으로 한 번 더 나누는게 적은 방법?
        if(i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);   // 3. 2로 한 번 더 나누는게 적은 방법?
    }

    cout << dp[n];

    return 0;
}   