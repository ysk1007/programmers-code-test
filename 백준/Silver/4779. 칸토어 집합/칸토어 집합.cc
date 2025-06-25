#include<iostream>
#include<cmath>
using namespace std;

// 칸토어 집합 #4779

string div(string str){
    if(str.size() == 1) return "-";

    string result;
    int size = str.size() / 3;

    string s1 = str.substr(0,size);
    string s2;
    for(int i = 0; i < size ; i++){
        s2.append(" ");
    }
    string s3 = str.substr(str.size() - size);

    if(s1.size() != 1){
        s1 = div(s1);
        s3 = div(s3);
    }
    
    result = s1 + s2 + s3;
    return result;
}

int main(){
    int n;
    while(cin >> n){
        string str = "";

        for(int i = 0 ; i < pow(3,n) ; i++){
            str.append("-");
        }

        cout << div(str) << "\n";
    }

    return 0;
}