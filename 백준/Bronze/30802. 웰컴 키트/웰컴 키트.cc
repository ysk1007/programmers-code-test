#include<iostream>
#include<vector>
using namespace std;

// 웰컴 키트 #30802
int main(){
    int n;  // 참가자 수
    vector<int> size;
    int s;
    int t,p;    // 티셔츠 묶음, 펜 묶음

    int tOrder = 0, pOrder = 0;

    cin >> n;

    for(int i = 0 ; i < 6 ; i++){
        cin >> s;
        size.push_back(s);
    }

    cin >> t >> p;

    for(auto s : size){
        tOrder += s%t == 0 ? s/t : (s/t) + 1 ;
    }

    pOrder = n / p;
    
    cout << tOrder << "\n";
    cout << pOrder << " " << n % p;
}