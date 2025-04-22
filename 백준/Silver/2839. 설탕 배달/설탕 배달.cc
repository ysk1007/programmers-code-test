#include<iostream>
#include<vector>
using namespace std;

// 설탕 배달 #2839
int main(){
    int t, result = 9999;
    vector<int> vc;
    cin >> t;

    if(t % 5 == 0) vc.push_back(t / 5);
    if(t % 3 == 0) vc.push_back(t / 3);
    
    int i = 0;
    while(t > 3){
        i++;
        t -= 3;
        if(t % 5 == 0){
            vc.push_back((t / 5) + i);
            break;
        }
    }


    if(vc.empty()){
        cout << -1;
        return 0;
    }

    for(int i : vc){
        result = min(result,i);
    }

    cout << result;
    return 0;
}