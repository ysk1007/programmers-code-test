#include<iostream>
#include<map>
using namespace std;

// 회사에 있는 사람 #7785
int main(){
    map<string,bool,greater<string>> company;
    int t;
    string name,log;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> name >> log;
        company[name] = (log == "enter" ? true : false);
    }

    for(auto employee : company){
        if(employee.second) cout << employee.first << "\n";
    }
}