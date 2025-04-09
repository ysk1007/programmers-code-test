#include<iostream>
#include<string>
using namespace std;

// 그대로 출력하기 #11718
int main(){
    string str;
    while(getline(cin,str)){
        cout << str << "\n";
    }

    return 0;
}