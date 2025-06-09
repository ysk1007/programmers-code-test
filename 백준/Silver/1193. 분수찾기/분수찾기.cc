#include<iostream>

using namespace std;

// 분수찾기 #1193

int main(){
    int t;
    pair<int,int> result = {1,1};
    cin >> t;

    if(t == 1){
        cout << result.first << "/" << result.second;
        return 0;
    }

    t -= 1;
    result.second++;
    
    bool flag = true;
    for(int i = 1 ; i < t ; i++){
        if(flag && result.second == 1){
            result.first++;
            flag = false;
        }
        else if(!flag && result.first == 1){
            result.second++;
            flag = true;
        }
        else if(flag){
            result.first++;
            result.second--;
        }
        else if(!flag){
            result.first--;
            result.second++;
        }
    }

    cout << result.first << "/" << result.second;
}