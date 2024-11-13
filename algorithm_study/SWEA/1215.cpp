#include<iostream>

using namespace std;

string str[8][8];
int len = 0;

void input_data() {
    cin >> len;
    string s;
    for(int i = 0; i < 8; i++) {
        cin >> s;
        for(int j = 0; j < 8; j++) {
            str[i][j] = s[j];
        }
    }
}

bool check(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    int test_case;
    int T = 10;
    
    for(test_case = 1; test_case <= T; ++test_case) {
        input_data();
        int result = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8 - len + 1; j++) {
                string temp;
                for(int z = j; z < j+len; z++) {
                    temp += str[i][z];
                }
                if (check(temp)) {
                    result++;
                }
            }
        }
        
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8 - len + 1; j++) {
                string temp;
                for(int z = j; z < j+len; z++) {
                    temp += str[z][i];
                }
                if (check(temp)) {
                    result++;
                }
            }
        }
        
        cout << "#" << test_case<<" " << result << '\n';
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
