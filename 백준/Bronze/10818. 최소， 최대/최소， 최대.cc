#include<iostream>

using namespace std;

// 최소,최대 #10818
int main(){
    int n = 0, minN = 1000000, maxN = -1000000;
    cin >> n;
    while(cin >> n){
        maxN = max(maxN,n);
        minN = min(minN,n);
    }
    cout << minN << " " << maxN;
    return 0;
}