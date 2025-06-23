#include<iostream>
#include<stack>
using namespace std;

// 도키도키 간식드리미 #12789
int main(){
    int t,n,target = 1;
    stack<int> st;
    cin >> t;

    for(int i = 0; i < t; i++){

        while(!st.empty() && st.top() == target){
            st.pop();
            target++;
        }
        
        cin >> n;

        if(target != n) st.push(n);
        else target++;
    }

    while(!st.empty()){
        int temp = st.top();

        if(target != temp){
            cout << "Sad";
            return 0;
        }
        else{
            st.pop();
            target++;
        }
    }

    cout << "Nice";
    return 0;
}