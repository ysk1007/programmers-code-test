#include<iostream>

using namespace std;

// 계단 오르기 #2579
int main(){
    int t, result = 0;
    cin >> t;
    int score[t+1] = {0};
    int dp[t+1] = {0};

    for(int i = 1 ; i <= t ; i++){
        cin >> score[i];
    }

    dp[1] = score[1];
    dp[2] = score[1] + score[2];

    for(int j = 3 ; j <= t ; j++){
        dp[j] = max(
            score[j] + dp[j-2],             // 마지막에 두 칸 뛰었냐?
            score[j] + score[j-1] + dp[j-3] // 마지막에 연속해서 올라갔냐?
        );
    }

    cout << dp[t];
}