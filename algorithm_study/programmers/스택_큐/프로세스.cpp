//
//  프로세스.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/22.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

deque<pair<int, int>> de;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    int maxx = 0;
    
    for(int i = 0; i < priorities.size(); i++){
        de.push_back(pair(i, priorities[i]));
    }
    sort(priorities.begin(), priorities.end(), greater<int> ());
    
    while(true){
        if(de.front().second < priorities[maxx] ){
            de.push_back(pair(de.front().first, de.front().second));
            de.pop_front();
        }
        
        else if (priorities[maxx] == de.front().second){
            maxx++;
            
            if(location == de.front().first){
                answer = maxx;
                break;
            }
            de.pop_front();
        }
        
        
    }

    
    
    
    
    
    
    return answer;
}
