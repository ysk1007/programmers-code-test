#include<iostream>
using namespace std;

// A + B - C #31403
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    string temp = to_string(b);

    cout << a + b - c << "\n";

    for(int i = 0 ; i < temp.size() ; i++){
        a *= 10;
    }

    cout << a + b - c;
}