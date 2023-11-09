//
//  숫자 문자열과 영단어.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/9/23.
//

#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

int solution(string s) {
    int answer = 0;
    regex r;
    for(int i = 0; i < numbers.size(); i++) {
        r = numbers[i];
        s = regex_replace(s, r, to_string(i));
    }
    answer = stoi(s);
    return answer;
}

int main() {
    cout << solution("23fourfourfourfour5six7");
}
