#include<iostream>
#include<stack>
using namespace std;

// 동전 0 #11047

stack<int> stk;
int n,k,a;

int main(){
    cin >> n >> k;
    while(n--){
        cin >> a;
        stk.push(a);
    }

    int count = 0;
    while(k > 0){
        if(stk.top() > k) stk.pop();
        else{
            count += k / stk.top();
            k = k % stk.top();
        }
    }

    cout << count;
}