#include<iostream>
#include<vector>
using namespace std;

int minCount = 9999;
vector<string> vc;

int dot(int x, int y, char c){
    int count = 0;
    char color = c; // 색 저장
    for(int i = 0 ; i < 8 ; i++){

        for(int j = 0 ; j < 8 ; j++){
            // 홀수
            if((i + j) & 1) {
                if(color == vc[x+i][y+j]) count++;
            }
            // 짝수
            else {
                if(color != vc[x+i][y+j]) count++;
            }
        }

        if(count >= minCount) return count;
    }
    return count;
}

// 체스판 다시 칠하기 #1018
int main(){
    int h,w,count = 99999;
    char color;
    string s;
    cin >> h >> w;

    for(int i = 0 ; i < h ; i++){
        cin >> s;
        vc.push_back(s);
    }

    for(int j = 0 ; j < h - 7 ; j++){
        for(int k = 0 ; k < w - 7 ; k++){
            minCount = min(minCount,min(dot(j,k,'W'),dot(j,k,'B')));
        }
    }



    cout << minCount;
    
    return 0;
}