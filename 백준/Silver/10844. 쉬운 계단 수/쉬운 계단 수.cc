#include<iostream>

using namespace std;

// 쉬운 계단 수 #10844

int main(){
    int n;
    long long dp[101][10] = {0};            // dp[자리수][0~10으로 끝나는 수]

    cin >> n;
    for(int i = 0 ; i <= 9 ; i++){
        if(i==0) continue;
        dp[1][i] = 1;
    }

    for(int j = 2 ; j <= n ; j++){
        for(int k = 0 ; k <= 9 ; k++){
            // 0 로 끝나는 수는 1로 끝나야만 만들 수 있다.
            if(k==0) dp[j][0] = dp[j-1][1] % 1000000000LL;

            // 9 로 끝나는 수는 8로 끝나야만 만들 수 있다.
            else if(k==9) dp[j][9] = dp[j-1][8] % 1000000000LL;

            // 1 ~ 8 까지 각 끝나는 수는 n + 1, n - 1 가 만들어 준다.
            else{
                dp[j][k] = dp[j-1][k-1] + dp[j-1][k+1] % 1000000000LL;
            }
        }        
    }

    // 결과 출력
    long long sum = 0;
    for(int l = 0 ; l <= 9 ; l++){
        sum += dp[n][l] % 1000000000LL;
    }

    cout << sum % 1000000000LL;;
}