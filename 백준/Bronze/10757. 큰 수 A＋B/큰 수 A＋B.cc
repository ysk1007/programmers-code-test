#include<iostream>

using namespace std;

// 큰 수 A+B #10757
int main(){
    string a = "",b = "",result = "";
    cin >> a >> b;
    if(a.size() < b.size()) swap(a,b);

    for(int i = b.size(); i < a.size() ; i++){
        b = "0" + b;
    }

    int temp = 0;
    for(int i = 0 ; i < b.size() ; i++){
        int sum = (a[a.size() - 1 - i] - '0') + (b[b.size() - 1- i] - '0');
        sum += temp;
        temp = 0;
        if(sum >= 10){
            sum -= 10;
            temp = 1;
        }
        result = to_string(sum) + result;
    }

    cout << (temp != 0 ? to_string(temp) : "") + result;

    return 0;
}