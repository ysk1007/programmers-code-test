#include<iostream>
#include<stack>
using namespace std;

// 스택 #10828
int main(){
    int t,n;
    string s;
    stack<int> st;

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> s;

        if(s == "push"){
            cin >> n;
            st.push(n);
        }

        if(s == "top"){
            if(st.empty()) cout << -1 << "\n";
            else cout << st.top() << "\n";
        }

        if(s == "size") cout << st.size() << "\n";

        if(s == "pop"){
            if(st.empty()) cout << -1 << "\n";
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }

        if(s == "empty") cout << (st.empty() ? 1 : 0) << "\n";
    }
}