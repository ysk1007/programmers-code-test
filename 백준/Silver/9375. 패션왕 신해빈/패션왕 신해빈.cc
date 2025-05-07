#include<iostream>
#include<map>
#include<vector>
using namespace std;

// 패션왕 신해빈 #9375

int t,n,day,cs;
string type,item;

int main(){
    cin >> t;

    while(t--){ // 테스트 케이스 만큼
        map<string,vector<string>> m;
        day = -1;

        cin >> n;

        while(n--){ // 아이템 만큼
            cin >> item >> type;
            m[type].push_back(item);
        }

        cs = 1; // 경우의 수
        for(auto v : m){
            cs *= v.second.size() + 1;  // 안 뽑는 경우도 있으니까 +1
        }

        day += cs;

        cout << day << "\n";
    }

    return 0;
}