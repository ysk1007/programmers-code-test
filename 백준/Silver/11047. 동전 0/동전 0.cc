#include<iostream>
#include<stack>
using namespace std;

// 동전 0 #11047

stack<int> stk;
int n,k,a, count = 0;

int main(){
    cin >> n >> k;
    while(n--){
        cin >> a;
        stk.push(a);
    }

    while(k > 0){
        count += k / stk.top();
        k = k % stk.top();
        stk.pop();
    }

    cout << count;
}