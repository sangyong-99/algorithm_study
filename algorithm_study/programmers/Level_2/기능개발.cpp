//
//  기능개발.cpp
//  algorithm_study
//
//  Created by 신상용 on 8/29/24.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> datas;
    
    for(int i = 0; i < progresses.size(); i++) {
        int temp = ceil((100 - progresses[i]) / (double)speeds[i]);
        datas.push(temp);
    }
    
    while(!datas.empty()) {
        int standard = datas.front();   datas.pop();
        int counts = 1;
        while(!datas.empty()) {
            if (standard < datas.front()) {
                break;
            } else {
                counts++;
                datas.pop();
            }
        }
        answer.push_back(counts);
    }
    
    return answer;
}

int main() {
    vector<int> answer = solution({93, 30, 50}, {1, 30, 5});
}
