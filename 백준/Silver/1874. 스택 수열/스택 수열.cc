#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// 스택 수열 #1874
int main(){
    int t,n;
    string str="";
    cin >> t;
    stack<int> st;
    queue<int> que;

    // 큐 채우기
    for(int i = 1 ; i <= t ; i++){
        que.push(i);
    }

    int afterN = -1;
    while(t--){
        // 숫자 입력 받음
        cin >> n;

        // 전 숫자보다 큼
        if(n > afterN){

            // 큐가 비어있지 않다면, 그 숫자가 나오기 전까지 que에서 뽑은 후 스택에 넣기
            while(!que.empty() && que.front() != n){
                st.push(que.front());
                que.pop();
                str += "+\n";
            }

            // 큐가 비어있다면 불가능
            if(que.empty()){
                cout << "NO";
                return 0;
            }

            // 찾은 숫자 스택에 넣기
            st.push(que.front());
            que.pop();
            str += "+\n";

            // 그 숫자 빼기
            st.pop();
            str += "-\n";

        }
        // 전 숫자보다 작음
        else{
            // 스택이 비어있지 않다면, 그 숫자가 나오기 전까지 스택에서 뽑음
            while(!st.empty() && st.top() != n){
                st.pop();
                str += "-\n";
            }

            // 스택이 비어있다 -> 실패
            if(st.empty()){
                cout << "NO";
                return 0;
            }

            // 스택에서 뽑기
            st.pop();
            str += "-\n"; 
        }

        // 전 숫자 저장
        afterN = n;
    }

    // 과정 출력
    cout << str;

    return 0;

}