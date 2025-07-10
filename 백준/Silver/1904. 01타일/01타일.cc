#include<iostream>
using namespace std;

// 01타일 #1904

// N=1 { 1 } 1개
// N=2 { 00 , 11} 2개
// N=3 { 001, 100, 111} 3개
// N=4 { 0011, 0000, 1001, 1100, 1111} 5개
// N=5 { 00111, 10011, 11001, 11100, 00001, 00100, 10000, 11111} 8개

int main(){
    int n;
    long long a = 1, b = 2, temp = 0;

    cin >> n;

    if(n == 1){
        cout << 1;
        return 0;
    }
    if(n == 2){
        cout << 2;
        return 0;
    }

    for(int i = 3 ; i <= n ; i++){
        temp = (a + b) % 15746LL;   // 나눈 나머지는 미리미리 계산 하자
        a = b;
        b = temp;
    }

    cout << temp;
}