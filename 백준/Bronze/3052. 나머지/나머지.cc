#include<iostream>
#include<map>
using namespace std;

// 나머지 #3052
int main(){
    map<int,int> m;
    int n,sum = 0;
    while(cin >> n){
        m[n%42]++;
    }
    cout << m.size();
    return 0;
}