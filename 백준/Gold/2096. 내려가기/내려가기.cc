#include<iostream>
#include<vector>
using namespace std;

// 내려가기 #2096

int n,a,b,c;

int tMax(int a,int b, int c){
    return max(max(a,b),c);
}

int tMin(int a,int b, int c){
    return min(min(a,b),c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> maxWin(3);
    vector<int> minWin(3);

    cin >> maxWin[0] >> maxWin[1] >> maxWin[2];
    minWin = maxWin;

    for(int i = 1 ; i < n ; i++){
        cin >> a >> b >> c;

        int prevMax0 = maxWin[0], prevMax1 = maxWin[1], prevMax2 = maxWin[2];
        int prevMin0 = minWin[0], prevMin1 = minWin[1], prevMin2 = minWin[2];

        maxWin[0] = max(prevMax0,prevMax1) + a;
        maxWin[1] = tMax(prevMax0,prevMax1,prevMax2) + b;
        maxWin[2] = max(prevMax1,prevMax2) + c;
        

        minWin[0] = min(prevMin0,prevMin1) + a;
        minWin[1] = tMin(prevMin0,prevMin1,prevMin2) + b;
        minWin[2] = min(prevMin1,prevMin2) + c;
    }

    cout << tMax(maxWin[0],maxWin[1],maxWin[2]) << " " << tMin(minWin[0],minWin[1],minWin[2]);
}