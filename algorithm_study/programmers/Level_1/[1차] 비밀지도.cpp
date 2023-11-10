//
//  [1차] 비밀지도.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/10/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i <n; i++){
        arr1[i] = arr1[i]|arr2[i];
        string ans = "";
        for(int j = 0; j<n; j++){
            if(arr1[i] % 2 == 0) ans = " " + ans;
            else ans = "#" + ans;
            arr1[i] = arr1[i] >> 1;
        }
        answer.push_back(ans);
    }
    return answer;
}

int main() {
    vector<string> answer;
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    answer = solution(n, arr1, arr2);
    
    for(string ss: answer) {
        cout << ss << ",";
    }
    cout << endl;
}
