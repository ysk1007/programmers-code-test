#include<iostream>
#include<deque>
#include<sstream>
using namespace std;

// AC #5430

int t,n;
string p;
string arrStr;
stringstream ss;
string s;

void AC(deque<string> que){
    string result = "";
    bool r = false;
    for(auto c : p){
        if(c == 'R') r = !r;
        else{ // c == 'D'
            if(que.size() == 0){
                cout << "error" << "\n";
                return;
            }

            if(!r) que.pop_front();
            else que.pop_back();
        }
    }

    int size = que.size();
    
    if(size == 0){
        cout << "[]" << "\n";
        return;
    }

    result.append("[");
    for(int i = 0 ; i < size ; i++){
        if(r){
            result.append(que.back() + ",");
            que.pop_back();
        }
        else{
            result.append(que.front() + ",");
            que.pop_front();
        }
    }
    result[result.length() - 1] = ']';
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        deque<string> que;
        cin >> p >> n >> arrStr;

        // '[', ']' 제거
        arrStr = arrStr.substr(1,arrStr.length() - 2);

        // 파싱해서 배열에 넣음
        stringstream ss(arrStr);
        while(getline(ss,s,',')){
            que.push_back(s);
        }

        AC(que);
    }
}