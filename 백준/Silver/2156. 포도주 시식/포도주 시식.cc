    #include<iostream>
    #include<vector>
    using namespace std;

    // 포도주 시식 #2156
    int main(){
        int t, result = 0;
        cin >> t;
        vector<int> vc(t+1);            // 포도주
        vector<int> dp(t+1,0);          // dp

        for(int i = 1 ; i <= t ; i++){  // 포도주 초기화
            cin >> vc[i];
        }

        if(t==1){                       // 포도주가 1잔 밖에 없음
            cout << vc[1];
            return 0;
        }

        if(t==2){                       // 포도주가 2잔 밖에 없음
            cout << vc[1] + vc[2];
            return 0;
        }

        dp[1] = vc[1];                                      // dp[1]
        dp[2] = vc[2] + vc[1];                              // dp[2]
        dp[3] = max(dp[2],max(vc[3]+vc[1],vc[3]+vc[2]));    // dp[3]

        result = dp[3];                                     // 현재까지 최대 양은 dp[3]

        for(int i = 4 ; i <= t ; i++){
            dp[i] = max(dp[i-1],max(dp[i-2] + vc[i], dp[i-3] + vc[i] + vc[i-1]));   // 3가지 시나리오를 비교
            result = max(result, dp[i]);                                            // 결과 저장
        }

        cout << result; // 결과 출력
        return 0;
    }