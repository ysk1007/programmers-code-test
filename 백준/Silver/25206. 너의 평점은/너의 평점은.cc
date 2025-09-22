#include<iostream>

using namespace std;

// 너의 평점은 #20206
int main(){
    string title, grade = "";
    double score, total, result = 0.000000;

    for(int i = 0 ; i < 20 ; i++){
        cin >> title >> score >> grade;

        if(grade == "P") continue;

        double subjectScore = 0.0;
        if(grade == "A+") subjectScore = 4.5;
        else if(grade == "A0") subjectScore = 4.0;
        else if(grade == "B+") subjectScore = 3.5;
        else if(grade == "B0") subjectScore = 3.0;
        else if(grade == "C+") subjectScore = 2.5;
        else if(grade == "C0") subjectScore = 2.0;
        else if(grade == "D+") subjectScore = 1.5;
        else if(grade == "D0") subjectScore = 1.0;
        else subjectScore = 0.0;
        
        result += subjectScore * score;
        total += score;
    }

    cout.precision(7);                              // 소수점 출력 범위 설정

    if(result == 0){
        cout << "0.000000";
    }
    else{
        cout << result / total;
    }

    return 0;
}