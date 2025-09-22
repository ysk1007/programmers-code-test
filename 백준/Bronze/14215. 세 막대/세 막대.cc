#include<iostream>

using namespace std;

// 세 막대 #14215

int triangle(int a, int b, int c){  // a를 긴 변으로 간주
    int len = 0;

    if(a < b || a < c) return len;  // a가 긴 변이 아니면 return

    // 가장 긴 변의 길이 < 나머지 두 변의 길이의 합
    if(a < b + c){                  // 삼각형 조건 성립
        len = a + b + c;
    }
    else{                           // 삼각형 조건 미성립
        len = (b+c-1) + b + c;      // 가장 긴 변을 나머지 두 변의 길이의 합보다 -1 작으면 최대 사용 가능한 긴 변
    }

    return len;
}

int main(){
    int a,b,c = 0;

    cin >> a >> b >> c;

    cout << max(triangle(a,b,c),max(triangle(b,c,a),triangle(c,a,b)));
}