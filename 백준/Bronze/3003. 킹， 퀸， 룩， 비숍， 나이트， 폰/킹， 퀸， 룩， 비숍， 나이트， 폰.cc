#include<iostream>

using namespace std;

// 킹, 퀸, 룩, 비숍, 나이트, 폰 #3003
int main(){
    //  킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개
    int arr[] = {1,1,2,2,2,8};
    int j = 0;

    for(int i = 0 ; i < 6 ; i++){
        cin >> j;
        cout << arr[i] - j << " ";
    }

    return 0;
}