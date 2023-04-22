//
//  다리를 지나는 트럭.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/22.
//

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

queue<int> qu;
int truck_weight = 0;   //다리위에 있는 트럭의 무게
int truck_index = 0;
int timess = 0;
int truck_count = 0;    //트럭 나온 개수

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    int answer = 0;
    for(int i = 0; i < bridge_length; i++){ //qu 브릿지 길이만큼 큐에 추가함
        qu.push(0);
    }
    
    while(truck_count != truck_weights.size()){ // 나오는 트럭 개수가 트럭 개수랑 같나?
        if(qu.front() != 0){    //qu 프론트가 0이 아니면 트럭 나온 개수 + 1
            truck_count++;
        }
        truck_weight -= qu.front(); // 처음수를 빼줌
        qu.pop();   //큐에꺼를 빼줌
    
        if(truck_weight < weight && (weight-truck_weight) >= truck_weights[truck_index] && truck_index <= (truck_weights.size()-1)){ //트럭이 들어갈 수 있으면
            truck_weight += truck_weights[truck_index];
            qu.push(truck_weights[truck_index]);
            truck_index++;
            
        }
        else qu.push(0);
        timess++;
    }
    answer = timess;
    return answer;
}
