//
//  2016년.cpp
//  algorithm_study
//
//  Created by 신상용 on 12/7/23.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int month_Data[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string week_Data[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
int day_count(int a, int b) {
    int count = 0;
    for(int i = 0; i < a-1; i++) {
        count += month_Data[i];
    }
    count += b - 1;
    return count;
}

string solution(int a, int b) {
    int date_count = day_count(a, b);
    return week_Data[date_count % 7];
}
