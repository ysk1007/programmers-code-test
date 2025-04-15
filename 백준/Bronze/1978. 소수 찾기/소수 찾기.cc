#include<iostream>
using namespace std;

// 소수 판별
bool decimal(int n){
    if(n == 1) return false;
    
    for(int i = 2 ; i < n ; i++){
        if(n % i == 0) return false;
    }
    return true;
}

// 소수 찾기 #1978
int main(){
    int n,result = 0;
    cin >> n;

    while(cin >> n){
        result += decimal(n) ? 1 : 0;
    }

    cout << result;

    return 0;
}