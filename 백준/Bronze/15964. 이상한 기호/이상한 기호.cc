#include<iostream>

using namespace std;

int method(int a, int b){
    return (a+b)*(a-b);
}

// 이상한 기호 #15964
int main(){
    int a,b;
    cin >> a >> b;
    cout << method(a,b);
}