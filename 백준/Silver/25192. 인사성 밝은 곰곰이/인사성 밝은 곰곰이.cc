#include<iostream>
#include<map>
using namespace std;

// 인사성 밝은 곰곰이 #25192
int main(){

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, result = 0;
    string name;
    map<string,bool> check;

    cin >> t;                   // 데이터 수
    
    while(t--){
        cin >> name;            // 이름 입력 받음

        if(name == "ENTER"){    // 새로운 사용자가 입장
            check.clear();      // 첫인사 여부 체크 맵을 초기화
            continue;
        }

        if(!check[name]){       // 이름이 들어왔는데 첫인사를 안 했음
            check[name] = true; // 첫인사 체크하고
            result++;           // 카운트 +1
        }
    }

    cout << result;             // 결과 출력

    return 0;
}