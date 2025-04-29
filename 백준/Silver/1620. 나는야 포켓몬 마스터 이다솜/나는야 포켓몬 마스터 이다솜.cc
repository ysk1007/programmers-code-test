#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

// 나는야 포켓몬 마스터 이다솜 #1620

map<string,int> poketBook;
vector<string> poketName;
int n,m;
string str;
int main(){

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    poketName = vector<string>(n + 1);
    for(int i = 1 ; i <= n ; i++){
        cin >> str;
        poketBook[str] = i;
        poketName[i] = str;
    }

    while(m--){
        cin >> str;

        if(isdigit(str[0])){    // 도감 번호가 들어옴
            cout << poketName[stoi(str)] << "\n";
        }
        else{   // 포켓몬 이름이 들어옴
            cout << poketBook[str] << "\n";
        }
    }
}