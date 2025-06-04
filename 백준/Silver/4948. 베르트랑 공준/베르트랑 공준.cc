#include<iostream>
#include<vector>
using namespace std;

// 베르트랑 공준 #4948

vector<int> vc;
int n, maxN = 0;

void eratos(vector<bool> &demical){
    demical[0] = false;
    demical[1] = false;
    for(int i = 2 ; i <= maxN * 2 ; i++){
        if(demical[i] == false) continue;

        for(int j = i*2 ; j <= maxN * 2 ; j += i){
            demical[j] = false;
        }
    }
}

int main(){
    while(cin >> n){
        if(n == 0) break;

        maxN = max(maxN,n);
        vc.push_back(n);
    }

    vector<bool> demical((maxN * 2)+1, true);

    eratos(demical);

    for(auto v : vc){
        int count = 0;
        for(int i = v+1 ; i <= v * 2 ; i++){
            if(demical[i]) count++;
        }

        cout << count << "\n";
    }

    return 0;
}