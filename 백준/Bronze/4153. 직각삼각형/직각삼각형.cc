#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;

// 직각삼각형 #4153
int main(){
    string str;
    while(getline(cin,str)){
        if(str == "0 0 0") break;
        stringstream ss(str);
        string temp;
        vector<int> vc;

        while(ss >> temp){
            vc.push_back(stoi(temp));
        }

        sort(vc.begin(),vc.end());

        cout << (pow(vc[2],2) == pow(vc[1],2) + pow(vc[0],2) ? "right" : "wrong") << "\n";


    }
    return 0;
}