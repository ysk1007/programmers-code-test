#include<iostream>
#include<map>
using namespace std;

// 숫자 카드 #10815

int n,m,card;
map<int,int> cards;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    while(n--){
        cin >> card;
        cards[card]++;
    }

    cin >> m;
    while(m--){
        cin >> card;
        cout << (cards[card] > 0 ? 1 : 0) << " ";
    }
}