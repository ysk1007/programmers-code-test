#include<iostream>

using namespace std;

long long method(long long a, long long b){
    return (a+b)*(a-b);
}

// 이상한 기호 #15964
int main(){
    long long a,b;
    cin >> a >> b;
    cout << method(a,b);
    return 0;
}