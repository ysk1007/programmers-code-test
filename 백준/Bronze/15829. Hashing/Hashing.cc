#include<iostream>
#include<cmath>
using namespace std;

// Hashing #15829
int main(){
    int n;
    long long result = 0;
    string s;
    cin >> n >> s;

    int i = 0;
    for(char c : s){
        int sum = ((c - 'a') + 1) * pow(31,i);
        result += sum;
        i++;
    }

    cout << result;

    return 0;
}