//
//  짝지어 제거하기.cpp
//  algorithm_study
//
//  Created by 신상용 on 7/7/24.
//

#include <iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> ss;
    
    for(int i = 0; i< s.length(); i++) {
        ss.push(s[i]);
        
        while(1) {
            if (ss.size() >= 2){
                char c1 = ss.top();
                ss.pop();
                char c2 = ss.top();
                if (c1 == c2) ss.pop();
                else {ss.push(c1); break;}
            } else {break;}
        }
    }
    if (ss.empty()) return 1;
    return 0;

    // return answer;
}

// int solution(string s)
// {
//     int answer = -1;

//     while(s.length() != 0){
//         bool bb = false;
//         for(int i = 1; i < s.length(); i++) {
//             if (s[i-1] == s[i]) {
//                 s.erase(i-1, 2);
//                 bb = true;
//                 break;
//             }
//         }
        
//         if (!bb) {
//             return 0;
//         }
//     }
//     return 1;
    

//     return answer;
// }
