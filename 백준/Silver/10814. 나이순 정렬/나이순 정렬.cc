#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

bool compare(tuple<int,int,string> a, tuple<int,int,string> b){
    if(get<1>(a) == get<1>(b)){ // 나이가 같으면
        return get<0>(a) < get<0>(b);   // 들어온 순서
    }

    return get<1>(a) < get<1>(b);   // 나이 순서
}

// 나이순 정렬 #10814
int main(){
    int t = 0,age = 0;
    string name = "";
    // 가입순서, 나이, 이름름
    vector<tuple<int,int,string>> vc;
    cin >> t;
    
    for(int i = 0 ; i < t ; i++){
        cin >> age >> name;
        tuple<int,int,string> t = {i,age,name};
        vc.push_back(t);
    }

    sort(vc.begin(),vc.end(),compare);

    for(auto v : vc){
        cout << get<1>(v) << " " << get<2>(v) << "\n";
    }

    return 0;
}