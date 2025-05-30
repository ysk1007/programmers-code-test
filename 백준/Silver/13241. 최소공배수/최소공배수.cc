#include<iostream>
using namespace std;

// 최대 공약수(유클리드 호제법)
long long gcd(long long a, long long b){
    long long n1 = b;
    long long n2 = a;
    long long mod = -1;

    // 나눈 값을 나머지로 계속 나누기
    while(mod != 0){
        mod = n1 % n2;
        n1 = n2;
        n2 = mod;
    }

    return n1;
}

// 최소 공배수
long long lcm(long long a, long long b){
    // 두 수의 곱 = 최소 공배수 * 최대 공약수
    return (a * b) / gcd(a,b);
}

// 최소 공배수 #13241
int main(){
    long long a,b;
    cin >> a >> b;

    cout << lcm(a,b);
}
