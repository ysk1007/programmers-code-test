#include<iostream>

using namespace std;

// 달팽이는 올라가고 싶다 #2869
int main(){
    int a,b,v,vv,day = 0,h = 0;
    cin >> a >> b >> v;

    int p = a - b;          // 하루에 올라갈 수 있는 이동
    vv = v - a;             // 최소 목표 : 이 목표까지 왔다면 다음날 무조건 목표에 도착할 수 있는 높이이

    day = vv / p;           // 최소 목표까지 가는데 걸리는 일

    if(vv % p != 0) day++;  // 만약 나누어 떨어지지 않았으면 하루가 더 필요요

    day++;                  // 최소 목표까지 와서 하루 더 지나야 함

    cout << day;

    return 0;
}