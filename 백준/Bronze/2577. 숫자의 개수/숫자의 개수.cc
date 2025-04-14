#include<iostream>
#include<vector>
using namespace std;

// 숫자의 개수 #2577
int main(){
    int a,b,c;
    long long n;
    vector<int> vc(10,0);

    cin >> a >> b >> c;
    n = a * b * c;

    while(n > 0){
        vc[n%10]++;
        n /= 10;
    }

    for(int i : vc){
        cout << i << "\n";
    }

    return 0;
}