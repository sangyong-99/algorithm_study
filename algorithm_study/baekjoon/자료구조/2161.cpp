//
//  2161.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/22.
//

#include <bits/stdc++.h>
using namespace std;

int N; vector<int> results; //초기값 N, 결과값 results
queue<int> qu;  // queue qu;
bool bb = true;

void input_data(){  //데이터 입력받고 qu에 순서대로 초기화
    cin >> N;
    for(int i = 1; i <= N; i++){
        qu.push(i);
    }
}

void print_results(){       //값을 출력
    for(int i: results){
        cout << i << " ";
    }
}

int main(){
    input_data();   //데이터 input
    while(qu.size() != 1){
        if (bb) { //bb true이면 제일 위에 있는 값을 버림
            results.push_back(qu.front());
            qu.pop();
        }
        else { // bb false이면 제일 위에 있는 값을 아래로 내림
            qu.push(qu.front());
            qu.pop();
        }
        bb = !bb;
        
    }
    results.push_back(qu.front());  //qu안에 1개 남은 값을 results에 삽입
    print_results();    //출력
}
