//
//  타켓 넘버.cpp
//  algorithm_study
//
//  Created by Shin Sangyong on 9/10/24.
//

#include <string>
#include <vector>

using namespace std;

int counts = 0, targets = 0;

void func(vector<int> numbers, int num, int sum) {
    if (num == numbers.size()) {
        if (sum == targets) {
            counts++;
        }
        return;
    }
    
    
    func(numbers, num + 1, sum + numbers[num]);
    func(numbers, num + 1, sum - numbers[num]);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    targets = target;
    func(numbers, 0, 0);
    
    
    return counts;
}
