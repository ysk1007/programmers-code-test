#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ATM #11399

vector<int> vc;
int t,n,result = 0,wait = 0;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vc.push_back(n);
    }
    
    sort(vc.begin(),vc.end());

    for(auto v : vc){
        wait += v;
        result += wait;
    }

    cout << result;

    return 0;
}