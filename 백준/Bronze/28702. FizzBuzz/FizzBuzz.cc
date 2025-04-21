#include<iostream>
#include<cctype>
using namespace std;

// FizzBuzz #28702
int main(){
    string s;
    int temp = 0;

    for(int i = 0 ; i < 3 ; i++){
        cin >> s;
        for(auto c : s){
            if(isdigit(c)){
                temp = stoi(s);
                temp += 3 - i;
                break;
            }
        }
    }

    if(temp % 3 == 0 && temp % 5 == 0) cout << "FizzBuzz";
    else if(temp % 3 == 0) cout << "Fizz";
    else if(temp % 5 == 0) cout << "Buzz";
    else cout << temp;

    return 0;
}