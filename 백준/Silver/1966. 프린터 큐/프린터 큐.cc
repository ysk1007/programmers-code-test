#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int t,n,m, file;
// 프린터 큐 #1966
int main(){
    
    // 빠른 입출력력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> t;
    while(t--){
        cin >> n >> m;

        vector<int> vc;
        queue<pair<int,int>> que;
        
        // que와 vc에 담기
        for(int i = 0 ; i < n ; i++){
            cin >> file;

            // {인덱스, 중요도}
            pair<int,int> p = {i,file};
            que.push(p);
            vc.push_back(file);
        }

        // 사이즈가 1이면 바로 return 1
        if(n == 1){
            cout << 1 << "\n";
            continue;
        }

        // pop한 횟수
        int count = 1;
        
        // 작업이 없을때 까지
        while(!que.empty()){

            bool b = true;  // 작업할 수 있나?
            for(int i = 0 ; i < vc.size() ; i++){

                // 높은 중요도가 있으면 뒤로
                if(vc[i] > que.front().second){
                    que.push(que.front());
                    que.pop();
                    b = false;
                    break;
                }
            }

            if(!b) continue;

            // 작업의 인덱스가 m 과 같다면
            if(que.front().first == m){
                cout << count << "\n";
                break;
            }
            
            // 중요도 vector에서 작업의 중요도 찾아서 지우기기
            int idx = find(vc.begin(),vc.end(),que.front().second) - vc.begin();
            vc.erase(vc.begin() + idx);
            
            que.pop();
            count++;

        }
    }


    return 0;
}