#include <vector>
using namespace std;
// 37:42 # 테케 성공
// 42:53 # 수정
vector<vector<int>> vc;

int check(int i, int j, int temp) {
    vc[i][j] = 0;
    int count = 1;

    if (i + 1 < vc.size() && vc[i + 1][j] == temp)
        count += check(i + 1, j, temp);
    if (i > 0 && vc[i - 1][j] == temp)
        count += check(i - 1, j, temp);
    if (j + 1 < vc[0].size() && vc[i][j + 1] == temp)
        count += check(i, j + 1, temp);
    if (j > 0 && vc[i][j - 1] == temp)
        count += check(i, j - 1, temp);

    return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vc = picture;
    int area = 0, range = 0;

    for (int i = 0; i < vc.size(); i++) {
        for (int j = 0; j < vc[i].size(); j++) {
            if (vc[i][j] != 0) {
                area++;
                int count = check(i, j, vc[i][j]);
                range = count > range ? count : range;
            }
        }
    }

    return {area, range};
}
