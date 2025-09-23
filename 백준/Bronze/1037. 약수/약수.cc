#include<iostream>

using namespace std;

// 약수 #1037
int main(){
    int t,n;
    int minN = 1000001, maxN = 1;

    cin >> t;
    for(int i = 0 ; i < t ; i++){
        cin >> n;
        minN = min(minN, n);
        maxN = max(maxN, n);
    }

    cout << minN * maxN;
}