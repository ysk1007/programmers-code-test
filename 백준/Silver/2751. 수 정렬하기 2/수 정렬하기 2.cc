#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 수 정렬하기 2 #2751
int main(){
    int t,n;
    vector<int> vc;
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> t;

    while(t--){
        cin >> n;
        vc.push_back(n);
    }

    sort(vc.begin(),vc.end());

    for(int i : vc){
        cout << i << "\n";
    }

    return 0;
}