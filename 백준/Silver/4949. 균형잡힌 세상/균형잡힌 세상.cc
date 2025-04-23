#include<iostream>
#include<stack>

using namespace std;


string balance(string str){
    stack<char> st;

    for(auto c : str){

        if(c == '(' || c == '[') st.push(c);

        if(c == ')' || c == ']'){
            if(!st.empty() && st.top() == '(' && c == ')') st.pop();
            else if(!st.empty() && st.top() == '[' && c == ']') st.pop();
            else{
                st.push(c);
                break;
            }
        }
    }

    return st.empty() ? "yes" : "no";
}

// 균형잡힌 세상 #4949
int main(){
    string s;
    string str;
    while(getline(cin,s)){
        str += s;
        if(str.size() == 1) continue;
        if(s.back() == '.'){
            cout << balance(str) << "\n";
            str = "";
        }
    }

    return 0;
}