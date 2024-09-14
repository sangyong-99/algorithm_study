//
//  튜플.cpp
//  algorithm_study
//
//  Created by 신상용 on 9/10/24.
//

#include <bits/stdc++.h>

using namespace std;

struct Datas{
    vector<int> d;
    int counts;
};

vector<Datas> results;

string bracErase(string& s) {
    s.erase(0, 1);
    s.erase(s.end() - 1);
    
    return s;
}

vector<string> split(string s, string delimi) {
    vector<string> vs;
    int it = 0;
    while (1) {
        auto au = s.find(delimi, it);
        if (au == string::npos) return vs;
        auto end = s.find("}", it);
        it = int(end) + 1;
        vs.push_back(s.substr(au + 1, end - au - 1));
        
    }
    return vs;
}

void numberSplit(string a) {
    istringstream str(a);
    vector<int> temps;
    string temp;
    while(getline(str, temp, ',')) {
        int i = stoi(temp);
        temps.push_back(i);
        
    }
    
    results.push_back(Datas{temps, int(temps.size())});
}

bool cmp(const Datas a1, const Datas a2) {
    if (a1.counts < a2.counts) {
        return true;
    }
    return false;
}

void vector_sort() {
    sort(results.begin(), results.end(), cmp);
}

vector<int> solution2() {
    vector<int> answer;
    for(auto result: results) {
        for(int temp: result.d) {
            if (find(answer.begin(), answer.end(), temp) == answer.end()) {
                answer.push_back(temp);
            }
        }
    }
    
    return answer;
}

vector<int> solution(string s) {
    bracErase(s);
    vector<string> as = split(s, "{");
    for(string a: as) {
        numberSplit(a);
        
    }
    vector_sort();
    vector<int> answer = solution2();
    return answer;
}

int main() {
    solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    return 0;
}
