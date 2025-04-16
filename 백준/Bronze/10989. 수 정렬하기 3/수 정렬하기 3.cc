#include<iostream>
#include<map>
using namespace std;

// 수 정렬하기 3 #10989
int main(){
    int t,n;
    map<int,int> map;
    ios::sync_with_stdio(false);
    cin.tie(NULL);  
    cin >> t;
    while(t--){
        cin >> n;
        map[n]++;
    }

    for(auto m : map){
        if(m.second == 0) continue;
        for(int i = 0 ; i < m.second ; i++){
            cout << m.first << "\n";
        }
    }

    return 0;
}