//
//  12015.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/08/16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int>& LIS, int left, int right, int target)
{
    int mid;
    
    //left와 right가 만날 때까지 target이 들어갈 자리를 찾는다.
    while (left < right)
    {
        mid = (left + right) / 2;
        //target이 현재 중간값보다 크면 left를 증가시킨다.
        if (target > LIS[mid])
            left = mid + 1;
        //작으면 right를 감소시킨다.
        else
            right = mid;
    }
    
    return right;
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    vector<int> numbers(N, 0);
    for (int i = 0; N > i; i++)
        cin >> numbers[i];
    
    vector<int> LIS(1, 0);
    LIS.emplace_back(numbers[0]);
    for (int i = 1; numbers.size() > i; i++)
    {
        //현재 원소가 LIS의 마지막 값보다 크면 그 값 뒤에 이어붙일 수 있기 때문에 push back한다.
        if (LIS.back() < numbers[i])
            LIS.emplace_back(numbers[i]);
        else
        {
            //아니라면 LIS 배열 원소 중 현재 원소보다 크거나 같은 첫번째 값을 현재 원소로 바꿔줘야 한다.
            //이진탐색으로 들어갈 인덱스를 찾는다.
            int index = BinarySearch(LIS, 0, LIS.size() - 1, numbers[i]);
            LIS[index] = numbers[i];
        }
    }
    
    //인덱스 번호가 최장 길이니까 총 길이에서 1을 뺀 값을 출력
    int answer = LIS.size() - 1;
    cout << answer;
    
    return 0;
}
