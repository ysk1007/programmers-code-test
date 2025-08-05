#include<iostream>

using namespace std;

// 포도주 시식 #2156
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int dp[100001] = {0};

    cin >> t;
    int al[t] = {0};

    for(int i = 0 ; i < t ; i++){
        cin >> al[i];
    }

    dp[1] = al[0];
    dp[2] = al[0] + al[1];

    if(t == 1) {cout << dp[1]; return 0;}
    if(t == 2) {cout << dp[2]; return 0;}

    for(int i = 3 ; i <= t ; i++){
        int case1 = dp[i-2] + al[i-1];
        int case2 = dp[i-3] + al[i-1] + al[i-2];
        int case3 = dp[i-1];

        dp[i] = max(case3,max(case1,case2));
    }

    // 디버깅
    // for(int i = 0 ; i <= t ; i++){
    //     cout << i << ": " << dp[i] << "\n";
    // }

    cout << dp[t];
}