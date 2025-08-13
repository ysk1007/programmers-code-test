#include<iostream>
#include<vector>
using namespace std;

// 가장 긴 증가하는 부분 수열 #11053
// key! 자기 자신을 끝으로 할 때 가장 긴 증가하는 부분수열의 길이
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[1001] = {0};
    int t;
    cin >> t;

    int num[t] = {0};

    for(int i = 0 ; i < t ; i++){
        cin >> num[i];
    }
    
    int result = 0;
    for(int i = 0 ; i < t ; i++){
        int n = num[i];                 // n으로 끝나는 수열
        int m = 0;                      // 제일 긴 수열 찾기
        for(int j = 0 ; j < i ; j++){   // 배열 돌면서 나보다 작은(작아야 그 뒤에 n이 붙음)수 찾음
            if(n > num[j]){
                m = max(m,dp[num[j]]);  // 나보다 작으면서 가장 긴 길이 찾음
            }
        }

        int len = m + 1;                // 가장 긴 길이에서 본인 붙여서 +1
        dp[n] = len;                    // n으로 끝나는 수열 길이 저장
        result = max(result,len);       // 최종 출력할 가장 긴 수열 길이 미리 저장
    }

    // 각 자리로 끝나는 길이 디버깅
    // for(auto n : num){
    //     cout << dp[n] << " ";
    // }
    // cout << "\n결과\n";

    cout << result;
    return 0;
}