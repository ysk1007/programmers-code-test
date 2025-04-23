#include<iostream>
#include<stack>
using namespace std;

// 제로 #10773
int main(){
    stack<int> st;
    int t,n,result = 0;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 0) st.pop();
        else st.push(n);
    }


    while(st.size()){
        result += st.top();
        st.pop();
    }
    
    cout << result;

    return 0;
}