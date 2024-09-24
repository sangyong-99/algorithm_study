//
//  주식가격.cpp
//  algorithm_study
//
//  Created by 신상용 on 9/24/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;
    
    for(int i = 0; i < prices.size(); i++) {
        while(!st.empty()) {
            int temp = st.top(); st.pop();
            if (prices[temp] > prices[i]) {
                answer[temp] = i - temp;
            } else {
                st.push(temp);
                break;
            }
        }
        st.push(i);
    }
    
    while(!st.empty()) {
        int temp = st.top(); st.pop();
        answer[temp] = prices.size() - 1 - temp;
    }
    
    return answer;
}
