//
//  1991.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/16.
//

#include <bits/stdc++.h>
using namespace std;

int N;
char node, left_node, right_node;
int arrays[27][4];
bool visited[27];
vector<int> results;

void data_reset(){
    for(int i = 0; i < 27; i++){
        visited[i] = false;
        results.clear();
    }
}

void input_data(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> node >> left_node >> right_node;
        if (left_node != '.'){
            arrays[node - 'A'][1] = left_node - 'A';
        }
        if (right_node != '.'){
            arrays[node - 'A'][2] = right_node - 'A';
        }
    }
}

void prefix(int number){
    visited[number] = true;
    results.push_back(number);
    for(int i = 1; i <= 2; i++){
        int aa = arrays[number][i];
        if(aa != -1){
            prefix(aa);
        }
    }
}

void midfix(int number){
    int aa = arrays[number][1];
    if (aa != -1){
        midfix(aa);
    }
    visited[number] = true;
    results.push_back(number);
    aa = arrays[number][2];
    if (aa != -1) {
        midfix(aa);
    }
}

void lastfix(int number){
    int aa = arrays[number][1];
    if (aa != -1){
        lastfix(aa);
    }
    aa = arrays[number][2];
    if (aa != -1) {
        lastfix(aa);
    }
    visited[number] = true;
    results.push_back(number);
}


int main(){
    for(int i = 0; i < 27; i++){
        for (int j = 0; j < 4; j++){
            arrays[i][j] = -1;
        }
    }
    input_data();
    prefix(0);
    for(int i = 0; i < N; i++){
        cout << char(results[i] + 'A');
    }
    cout << '\n';
    data_reset();
    midfix(0);
    for(int i = 0; i < N; i++){
        cout << char(results[i] + 'A');
    }
    cout << '\n';
    data_reset();
    lastfix(0);
    for(int i = 0; i < N; i++){
        cout << char(results[i] + 'A');
    }
}
