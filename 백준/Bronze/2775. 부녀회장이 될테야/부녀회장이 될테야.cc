#include<iostream>
#include<vector>
using namespace std;

// 부녀회장이 될테야 #2775
int main(){
    int t,k,n;
    cin >> t; // 테스트 케이스 개수
    while(t--){
        cin >> k >> n;  // k층 n호

        // 동적 크기 할당
        vector<vector<long long>> apt(k + 1, vector<long long>(n));

        // 0층 주민 입주
        for(int i = 0 ; i < n ; i++){
            apt[0][i] = i+1;
        }

        // 각 층별로 아래층 주민 계산해서 입주
        for(int i = 1 ; i <= k ; i++){
            long long sum = 0;
            for(int j = 0 ; j < n ; j++){
                sum += apt[i-1][j];
                apt[i][j] = sum;
            }
        }

        cout << apt[k][n-1] << "\n";
    }
}