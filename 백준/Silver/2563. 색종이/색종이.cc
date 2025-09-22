#include<iostream>

using namespace std;

// 색종이 #2563
int main(){
    int arr[101][101] = {0};                        // 배열
    int t,x,y, result = 0;

    cin >> t;

    while(t--){
        cin >> x >> y;

        for(int i = x ; i < x + 10 ; i++){
            for(int j = y ; j < y + 10 ; j++){
                if(arr[i][j] == 1) continue;        // 이미 방문 했으면 pass
                arr[i][j] = 1;                      // 방문 체크
                result++;                           // 넓이 + 1
            }
        }
    }
    
    cout << result;
}