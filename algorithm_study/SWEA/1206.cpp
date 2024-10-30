//
//  1206.cpp
//  algorithm_study
//
//  Created by 신상용 on 10/27/24.
//

#include <bits/stdc++.h>
using namespace std;

int test_case;
int T = 10, N;
int datas[1010];

void input_data() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> datas[i];
    }
}

int main(int argc, char** argv)
{
    for(test_case = 1; test_case <= T; ++test_case)
    {
        input_data();
        int answer = 0;
        for(int i = 2; i <= N - 3; i++) {
            int maxss = max({datas[i - 2], datas[i - 1], datas[i+1], datas[i+2]});
            if (datas[i] > maxss) {
                answer += datas[i] - maxss;
            }
        }
        
        cout << "#" << test_case << " " << answer << '\n';
    }
    return 0;
}
