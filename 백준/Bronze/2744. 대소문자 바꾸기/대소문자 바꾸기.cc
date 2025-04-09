#include<iostream>
#include<string>
using namespace std;

// 대소문자 바꾸기 #2744
int main(){
    string str;
    cin >> str;
    for(auto s : str){
        char c = isupper(s) ? tolower(s) : toupper(s) ;
        cout << c;
    }
}