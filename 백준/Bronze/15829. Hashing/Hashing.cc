#include<iostream>
#include<cmath>
using namespace std;

// Hashing #15829
int main(){
    int n;
    long long sum = 0;
    long long r = 1;
    long long m = 1234567891;
    string s;
    cin >> n >> s;

    for(int i = 0 ; i < n ; i++){
        sum += (long(s[i] - 'a' + 1) * r) % m;
        r = (r * 31) % m;
    }

    cout << sum % m;

    return 0;
}