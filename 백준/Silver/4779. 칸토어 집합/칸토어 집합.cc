#include<iostream>
#include<cmath>
using namespace std;

// 칸토어 집합 #4779

string cut(string l){
    if(l.length() == 1) return l;   // 길이가 1이면 그대로 return
    
    int len = l.length()/3;         // 1/3 길이
    string line1,line2,line3;       // 3개의 선으로 나누기
    
    line1 = l.substr(0,len);        // 선1은 원래 선의 1/3 가져오기
    line1 = cut(line1);             // 선1을 다시 cut() 호출 => 길이가 1될 때까지 계속 자르다가 돌아옴
    line2.resize(len,' ');          // 선2는 1/3 만큼 공백
    line3 = line1;                  // 선3은 선1 과 똑같음
    
    l = line1 + line2 + line3;      // 합쳐서 l return;
    return l;
}

int main(){
    string line = "";
    int n;

    while(cin>>n){
        line.resize(pow(3,n),'-');  // 3의 n제곱 만큼 길이 초기화

        cout << cut(line) << "\n";  // 자르고 출력
    }
}