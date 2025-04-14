#include<iostream>

using namespace std;

// 알람 시계 #2884
int main(){
    int h,m;
    cin >> h >> m;
    m -= 45;
    if(m < 0){
        m = 60 + m;
        h = h - 1 < 0 ? 24 + h - 1 : h - 1;
    }
    cout << h << " " << m;
}