#include<iostream>
#include<vector>
using namespace std;

// 덩치 #7568
int main(){
    int t,x,y;

    cin >> t;

    vector<pair<int,int>> vc(t);
    
    for(int i = 0 ; i < t ; i++){
        cin >> vc[i].first >> vc[i].second;
    }

    for(int i = 0 ; i < t ; i++){
        int rank = 1;
        for(int j = 0 ; j < t ; j++){
            if(i == j) continue;
            if(vc[j].first > vc[i].first && vc[j].second > vc[i].second) rank++;
        }
        cout << rank << " ";
    }
}