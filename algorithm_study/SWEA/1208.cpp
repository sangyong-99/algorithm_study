#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> v(100);
void input_data() {
    cin >> N;
    for(int i = 0; i < 100; i++) {
        cin >> v[i];
    }
}

bool isFlatten() {
    int diff = v[0] - v[99];
    if (diff <= 1) {
        return true;
    }
    return false;
}

int main(int argc, char** argv)
{
    int test_case;
    
    for(test_case = 1; test_case <= 10; ++test_case)
    {
        input_data();
        while(N > 0) {
            sort(v.begin(), v.end(), greater<>());
            if (isFlatten()) {
                break;
            }
            v[0]--;
            v[99]++;
            N--;
            
        }
        sort(v.begin(), v.end(), greater<>());
        cout << "#" << test_case << " " << v[0] - v[99] << '\n';
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
