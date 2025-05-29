#include<iostream>
using namespace std;

// 수학은 비대면강의입니다 #19532
int a,b,c,d,e,f,x,y;

int main(){
    cin >> a >> b >> c >> d >> e >> f;

    for(int i = -999 ; i < 1000 ; i++){
        for(int j = -999 ; j < 1000 ; j++){
            if(a * i + b * j == c && d * i + e * j == f){
                cout << i << " " << j;
                return 0;
            }
        }
    }
}