#include<iostream>

using namespace std;

// 카드 게임 #5522
int main(){
    int result = 0;
    int n = 0;

    while(cin >> n){
        result += n;
    }

    cout << result;

    return 0;
}