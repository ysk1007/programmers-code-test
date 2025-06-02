#include<iostream>

using namespace std;

// 분수 합 #1735

// 최대 공약수
int GCD(int a, int b){
    if(b > a) swap(a,b);

    int mod = 1;
    while(mod != 0){
        mod = a % b;
        a = b;
        b = mod;
    }

    return a;
}

int main(){
    int a,b,c,d,resultA,resultB,gcd;

    cin >> a >> b >> c >> d;

    resultA = (a*d) + (c*b);
    resultB = b*d;

    gcd = GCD(resultA,resultB);

    cout << resultA / gcd << " " << resultB / gcd;

    return 0;
}