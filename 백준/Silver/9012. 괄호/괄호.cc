#include<iostream>
#include<stack>
using namespace std;

// 괄호 #9012
int main(){
    int t;
    string str;
    cin >> t;

    while(t--){
        cin >> str;

        stack<char> st;
        for(auto c : str){
            if(!st.empty() && c == ')' && st.top() == '(') st.pop();
            else st.push(c);
        }

        cout << (st.empty() ? "YES":"NO") << "\n";
    }

    return 0;
}