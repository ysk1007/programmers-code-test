#include<iostream>
#include<map>
#include<set>
using namespace std;

// N과 M (1) #15649

int n,m;
set<string> st;


void DFS(int num,string str, map<int,bool> visited){
    string result = str;
    result += to_string(num);
    visited[num] = true;

    if(str.size() == m - 1){
        st.insert(result);
        return;
    }

    for(int i = 1 ; i <= n ; i++){
        if(i==num || visited[i]) continue;
        DFS(i,result,visited);
    }
}

int main(){
    cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        map<int,bool> visited;
        DFS(i,"",visited);
    }

    for(auto str : st){
        for(auto s : str){
            cout << s << " ";
        }
        cout << "\n";
    }

    return 0;
}