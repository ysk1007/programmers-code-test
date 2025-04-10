#include<iostream>
#include<cmath>
using namespace std;

// 검증수 #2475
int main(){
    int result = 0;
    int n = 0;
    while(cin >> n){
        result += pow(n,2);
    }
    cout << result % 10;
    return 0;
}