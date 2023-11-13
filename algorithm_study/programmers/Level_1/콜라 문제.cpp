//
//  콜라 문제.cpp
//  algorithm_study
//
//  Created by 신상용 on 11/13/23.
//

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a) {
        int temps = n / a;
        int tempsnumber = temps * b;
        answer += tempsnumber;
        n = (n % a) + tempsnumber;
    }
    
    return answer;
}
