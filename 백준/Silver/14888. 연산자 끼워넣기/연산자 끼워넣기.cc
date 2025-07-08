#include<iostream>
#include<vector>
using namespace std;

// 연산자 끼워넣기 #14888

int t, maxN = -1000000001, minN=1000000001;
int op[4];
vector<int> nums;

// 연산 타입 반환
string getOp(int i){
    if(i==0) return "+";
    else if(i==1) return "-";
    else if(i==2) return "*";
    else if(i==3) return "/";
    else "";
}

// 재귀함수(깊이, 연산자, 누적값)
void dfs(int depth, string oper, int result){
    
    // 연산자에 따라 누적값 계산
    if(oper == "+") result += nums[depth];
    else if(oper == "-") result -= nums[depth];
    else if(oper == "*") result *= nums[depth];
    else if(oper == "/") result /= nums[depth];
    
    // 깊이가 연산자 개수( 테케 갯수 - 1) 만큼 진행 됐다면 결과 저장
    if(depth == t - 1){
        maxN = max(maxN,result);
        minN = min(minN,result);
        return;
    }

    // 아직 연산 할 숫자가 더 있다면
    for(int i = 0 ; i < 4 ; i++){
        if(op[i] == 0) continue;        // 사용할 수 없는 연산자 건너뜀
        op[i]--;                        // 연산자 사용
        dfs(depth + 1,getOp(i),result); // 재귀
        op[i]++;                        // 연산자 반환
    }
}

int main(){
    // input
    cin >> t;
    nums = vector<int>(t);
    for(int i = 0 ; i < t ; i++){ cin >> nums[i]; }
    for(int j = 0 ; j < 4 ; j++){ cin >> op[j]; }

    // 함수 호출
    dfs(0,"",nums[0]);

    // output
    cout << maxN << "\n" << minN;

    return 0;
}