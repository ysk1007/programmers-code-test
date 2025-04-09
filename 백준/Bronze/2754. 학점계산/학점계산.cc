#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 학점계산 #2754
int main(){
    vector<string> vc = {"A+: 4.3","A0: 4.0","A-: 3.7",
                        "B+: 3.3", "B0: 3.0", "B-: 2.7",
                        "C+: 2.3", "C0: 2.0", "C-: 1.7",
                        "D+: 1.3", "D0: 1.0", "D-: 0.7",
                        "F: 0.0"};

    string str;
    cin >> str;
    for(auto v : vc){
        if(v.find(str) != string::npos) cout << v.substr(v.size() - 3);
    }
}