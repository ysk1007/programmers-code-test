#include<iostream>

using namespace std;

// 문자열 반복 #2675
int main(){
    int n = 0;
    int c = 0;
    string str = "";
    cin >> n;
    while(n--){
        cin >> c >> str;
        for(auto s : str){
            for(int i = 0 ; i < c ; i++){
                cout << s;
            }
        }
        cout << "\n";
    }
}