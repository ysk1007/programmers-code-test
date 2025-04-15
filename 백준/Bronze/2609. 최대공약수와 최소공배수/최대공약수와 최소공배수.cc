#include<iostream>
#include<numeric>
using namespace std;

// 최대공약수와 최소공배수 #2609
int main(){
    int a,b;
    cin >> a >> b;
    cout << gcd(a,b) << "\n" << lcm(a,b);
    return 0;
}