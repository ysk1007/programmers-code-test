#include<iostream>
#include<map>
using namespace std;

// 숫자 카드 2 #10816
int main(){
    map<int,int> map;
    int t,n;

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        map[n]++;
    }

    cin >> t;
    while(t--){
        cin >> n;
        cout << map[n] << " ";
    }

    return 0;
}