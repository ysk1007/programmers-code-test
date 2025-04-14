#include<iostream>
using namespace std;

// ACM 호텔 #10250
int main(){
    int t;  // 테스트 케이스 개수
    int h,w,n;
    string floor = "";
    string roomNum = "";

    cin >> t;

    while(t--){
        cin >> h >> w >> n;
        floor = n%h != 0 ? to_string(n%h) : to_string(h);
        roomNum = n%h != 0 ? to_string(n/h + 1) : to_string(n/h);
        if(roomNum.size() == 1) roomNum = "0" + roomNum;

        cout << floor + roomNum;

        floor = "";
        roomNum = "";
        
        cout << "\n";
    }

    return 0;
}