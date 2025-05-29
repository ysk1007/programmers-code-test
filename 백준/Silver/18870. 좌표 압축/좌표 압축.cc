#include<iostream>
#include<set>
#include<map>
using namespace std;

// 좌표 압축 #18870
int t,n;
map<int,int> mp;
set<int> st;
int main(){

    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    int arr[t];

    for(int i = 0 ; i < t ; i++){
        cin >> n;
        arr[i] = n;
        st.insert(n);
    }

    int i = 0;
    for(auto s : st){
        mp[s] = i;
        i++;
    }

    for(auto a : arr){
        cout << mp[a] << " ";
    }
}