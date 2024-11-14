#include<bits/stdc++.h>

using namespace std;

string temp;
bool bb;
int result = 0;
char datas[110][110];

void input() {
    //    cin >> temp;
    for (int i = 0; i < 100; i++) {
        cin >> temp;
        for (int j = 0; j < 100; j++) {
            datas[i][j] = temp[j];
        }
    }
}

bool check(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void solution() {
    for (int len = 1; len <= 100; len++) {    // 회문 길이
        for (int row = 0; row < 100; row++) {
            for (int j = 0; j < 100 - len + 1; j++) {
                temp = "";
                for (int z = 1; z < len; z++) {
                    temp += datas[row][z];
                }
                if (check(temp)) {
                    result = max(result, len);
                    bb = true;
                    break;
                }
            }
            if (bb) break;
        }
        if (bb) continue;
        bb = false;
        
        for (int row = 0; row < 100; row++) {
            for (int j = 0; j < 100 - len + 1; j++) {
                temp = "";
                for (int z = 1; z < len; z++) {
                    temp += datas[z][row];
                }
                if (check(temp)) {
                    result = max(result, len);
                    bb = true;
                    break;
                }
            }
            if (bb) break;
        }
    }
}

void clear() {
    result = 0;
    bb = false;
}

int main(int argc, char **argv) {
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case) {
        int count = 0;
        cin >> count;
        clear();
        input();
        solution();
        cout << "#" << count << " " << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
