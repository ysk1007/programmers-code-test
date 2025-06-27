#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// 별 찍기 - 10 #2447

// 처음부터 풀어서 정리함
vector<vector<char>> vc;
int n;

// 재귀 함수(시작 x, 시작 y, 배열 크기)
void star(int x, int y, int range){

    if(range == 1) return;

    // 공백 크기
    int newRange = range / 3;

    // 공백 뚫을 시작 위치
    int startX = x + newRange;
    int startY = y + newRange;

    // 중앙 뚫기
    for(int i = startX ; i < startX + newRange ; i++){
        for(int j = startY ; j < startY + newRange ; j++){
            vc[i][j] = ' ';
        }
    }

    // 재귀 함수 호출
    // 0 1 2
    // 3 X 5
    // 6 7 8
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(i == 1 && j == 1) continue;

            star(x + (i * newRange),y + (j * newRange),newRange);
        }
    }
}

int main(){
    cin >> n;

    // 배열 크기 초기화
    vc = vector<vector<char>>(n, vector<char>(n));

    // 내용 초기화
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            vc[i][j] = '*';
        }
    }

    // 함수 호출
    star(0,0,n);

    // 출력
    for(auto v : vc){
        for(auto star : v){
            cout << star;
        }
        cout << "\n";
    }
}


// 처음 풀었던 방식

// void div(pair<int,int> startPos,int weight){

//     if(startPos.first <= 0 || startPos.second <= 0 || startPos.first >= n || startPos.second >= n) return;
//     if(weight <= 0) return;

//     weight /= 3;
    
//     pair<int,int> endPos = {startPos.first + weight, startPos.second + weight};
//     // cout << startPos.first << "," << startPos.second << ": " << endPos.first << "," << endPos.second << " we : " << weight << "\n";
    
//     for(int i = startPos.first ; i < endPos.first ; i++){
//         for(int j = startPos.second ; j < endPos.second ; j++){
//             vc[i][j] = " ";
//         }
//     }
    
//     int posX = startPos.first / 3;
//     int posY = startPos.second / 3;

//     div({posX, posY}, weight);

//     div({posX, posY + (n / 3)}, weight);

//     div({posX, posY + ((n / 3) * 2)}, weight);

//     div({posX  + (n / 3) , posY}, weight);

//     div({posX + ((n / 3) * 2) , posY}, weight);

//     div({posX + (n / 3) , posY + (n / 3)}, weight);

//     div({posX + ((n / 3) * 2), posY + ((n / 3) * 2)}, weight);

//     div({posX + ((n / 3) * 2), posY + (n / 3)}, weight);

//     div({posX + (n / 3), posY + ((n / 3) * 2)}, weight);
// }

// int main(){
//     cin >> n;
    
//     int blank = n;
//     vc = vector<vector<string>>(n, vector<string>(n));

//     for(int i = 0 ; i < n ; i++){
//         for(int j = 0 ; j < n ; j++){
//             vc[i][j] = "*";
//         }
//     }

//     int pos = n/3;

//     div({pos,pos}, n);

//     for(auto v : vc){
//         for(auto t : v){
//             cout << t;
//         }
//         cout << "\n";
//     }
// }