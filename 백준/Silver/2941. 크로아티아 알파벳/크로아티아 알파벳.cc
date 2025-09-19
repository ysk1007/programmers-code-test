    #include<iostream>
    using namespace std;

    // 크로아티아 알파벳 #2941
    int main(){
        string alpha[] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
        string word = "";
        int pos = 0;

        cin >> word;
        int result = word.length();

        for(auto al : alpha){

            while(true){
                int index = word.find(al,pos);

                if(index == string::npos) break;

                pos = index + al.length();
                result--;
            }

            pos = 0;
        }

        cout << result;

        return 0;
    }