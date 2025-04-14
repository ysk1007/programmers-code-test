#include<iostream>

using namespace std;

// OX퀴즈 #8958
int main(){
    int n, p = 0;
    string s;

    cin >> n;
    while(n--){
        cin >> s;
        int pp = 0;
        for(auto c : s){
            pp = (c == 'O') ? pp + 1 : 0;
            p += pp;
        }
        cout << p << "\n";
        p = 0;
    }

    return 0;
}