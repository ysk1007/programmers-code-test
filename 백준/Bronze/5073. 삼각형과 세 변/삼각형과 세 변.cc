#include<iostream>

using namespace std;

// 삼각형과 세 변 #5073
// Equilateral :  세 변의 길이가 모두 같은 경우
// Isosceles : 두 변의 길이만 같은 경우
// Scalene : 세 변의 길이가 모두 다른 경우
// Invalid : 삼각형 조건 미성립

string triangle(int a, int b, int c){   // a를 가장 긴 변으로 간주
    
    if(a < b) swap(a,b);
    if(a < c) swap(a,c);

    if(a >= b + c) return "Invalid";
    else if(a == b && b == c) return "Equilateral";
    else if(a == b || b == c || a == c) return "Isosceles";
    else return "Scalene";
}

int main(){
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c;

    while(true){
        cin >> a >> b >> c;
        if(a == 0) break;

        cout << triangle(a,b,c) << "\n";
        
    }

    return 0;
}