#include<iostream>
#include<set>
using namespace std;

// 서로 다른 부분 문자열의 개수 #11478

int main(){
    set<string> st;
    string str;
    cin >> str;

    for(int i = 0 ; i < str.size() ; i++){
        for(int j = 1 ; j <= str.size() ; j++){
            st.insert(str.substr(i,j));
        }
    }

    cout << st.size();

    return 0;
}