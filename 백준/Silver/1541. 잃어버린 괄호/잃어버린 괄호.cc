#include<iostream>

using namespace std;

// 잃어버린 괄호 #1541
string s, temp;
int result = 0;
bool flag = false;

void cal(){
    if(flag && temp[0] == '+') result -= stoi(temp);
    else result += stoi(temp);
}

int main(){
    cin >> s;

    for(auto c : s){
        temp += c;
        if(!isdigit(c)){
            cal();
            temp = c;
        }
        if(c == '-') flag = true;
    }

    cal();

    cout << result;
}