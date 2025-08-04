#include<iostream>
using namespace std;

// 쉬운 계단 수 #10844
int main(){
    int n;
    long long dp[101][10] = {0};
    cin >> n;

    // 한 자리 계단 수는 모두 1임
    for(int i = 1 ; i <= 9 ; i++){
        dp[1][i] = 1;
    }

    // 두 자리 이상 계단 수 구하기
    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j <= 9 ; j++){
            if(j == 0) { dp[i][j] += dp[i-1][1]; }          // 이전 수가 0이 오려면 경우의 수는 1밖에 없음
            else if(j == 9){ dp[i][j] += dp[i-1][8]; }      // 이전 수가 9가 오려면 경우의 수는 8밖에 없음
            else { 
                dp[i][j] += dp[i-1][j-1] + dp[i-1][j+1];    // 이전 수가 j(그 외)가 오려면 경우의 수는 2가지씩 있음
            }                

            dp[i][j] %= 1000000000LL;
        }
    }

    // 마지막 단 합계
    long long sum = 0;
    for(int i = 0 ; i <= 9 ; i++){
        sum = (sum + dp[n][i]) % 1000000000LL;
    }

    // 디버깅
    // for(int i = 0 ; i <= n ; i++){
    //     for(int j = 0 ; j <= 9 ; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // 출력
    cout << sum;
    return 0;
}