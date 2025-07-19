//
//  주차요금계산.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/19/25.
//

#include <bits/stdc++.h>

using namespace std;

int timeCalculator(string times) {
    return stoi(times.substr(0, 2)) * 60 + stoi(times.substr(3, 2));
}

int calParkingAmt(int time, vector<int> fees) {
    int fee = 0;
    if (time <= fees[0]) {
        fee = fees[1];
    } else {
        fee = fees[1];
         fee += ceil(double(time - fees[0])/fees[2]) * fees[3];
    }
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    // <번호판, 입고 시간>
    map<string, int> in;
    // 누적 입고 시간
    map<string, int> totalInputTime;
    
    for(string s: records) {
        string temp;
        // 한개의 record씩 ' '을 기준으로 split 하는 부분
        istringstream str(s);
        vector<string> v;
        while(getline(str, temp, ' ')){
            v.push_back(temp);
        }
        // 입고일 경우 map : in에 넣는 부분
        if (v[2] == "IN") {
            in[v[1]] = timeCalculator(v[0]);
        } else {
            int timeCal = abs(in[v[1]] - timeCalculator(v[0]));
            totalInputTime[v[1]] += timeCal;
            in.erase(in.find(v[1]));
        }
    }
    
    for(auto it = in.begin(); it != in.end(); it++) {
        int timeCal = abs(it -> second - (23*60+59));
        totalInputTime[(it -> first)] += timeCal;
    }
    
   for(auto it = totalInputTime.begin(); it != totalInputTime.end(); it++) {
       answer.push_back(calParkingAmt(it -> second, fees));
   }
    
    return answer;
}
