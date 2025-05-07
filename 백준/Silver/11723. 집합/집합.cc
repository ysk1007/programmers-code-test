#include<iostream>
#include<set>
using namespace std;

// 집합 #11723
set<int> s;
set<int> st; //= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
string oper;
int t,n;

int main(){
    for(int i = 1 ; i <= 20 ; i++){
        st.insert(i);
    }

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> oper;

        if(oper == "add"){
            cin >> n;
            s.insert(n);
        }
        else if(oper == "remove"){
            cin >> n;
            if(s.find(n) == s.end()) continue;
            s.erase(s.find(n));
        }
        else if(oper == "check"){
            cin >> n;
            cout << (s.find(n) != s.end() ? 1 : 0) << "\n";
        }
        else if(oper == "toggle"){
            cin >> n;
            if(s.find(n) != s.end()) s.erase(s.find(n));
            else s.insert(n);
        }
        else if(oper == "all"){
            s = st;
        }
        else{   // oper == "empty"
            s.clear();
        }
    }

    return 0;
}