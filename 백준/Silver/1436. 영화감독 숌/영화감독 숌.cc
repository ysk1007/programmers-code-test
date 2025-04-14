#include<iostream>

using namespace std;

bool compare(int n){
    string s = to_string(n);
    return (s.find("666") != string::npos) ? true : false;
}

// 영화감독 숌 #1436
int main(){
    int n = 1;
    int title;
    int c = 666;
    cin >> title;
    while(n != title){
        while(true){
            c++;
            if(compare(c)) break;
        }
        n++;
    }

    cout << c;

    return 0;
}