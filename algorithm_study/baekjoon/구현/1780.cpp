//
//  1780.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/27.
//

#include <iostream>
using namespace std;

int N, countss = 0; short datas[2500][2500];    //countss 재귀 횟수
int results[3] = {0, };
int standard;

void input_data(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> datas[i][j];
        }
    }
}

bool checks(int start_row, int end_row, int start_col, int end_col){
    standard = datas[start_row][start_col];
    for(int i = start_row; i < end_row; i++){
        for(int j = start_col; j < end_col; j++){
            if(datas[i][j] != standard){
                return false;
            }
        }
    }
    return true;
}


void solution1(int start_row, int end_row, int start_col, int end_col, int re){
    if (checks(start_row, end_row, start_col, end_col)){
        results[standard + 1] = results[standard + 1] + 1;
        return;
    }
    else{
        int plus_var = re / 3;
        solution1(start_row, start_row + plus_var, start_col, start_col + plus_var, re/3);
        solution1(start_row, start_row + plus_var, start_col + plus_var, start_col + plus_var + plus_var, re/3);
        solution1(start_row, start_row + plus_var, start_col + plus_var + plus_var, start_col + plus_var + plus_var +plus_var, re/3);
        
        solution1(start_row + plus_var, start_row + (plus_var * 2), start_col, start_col + plus_var, re/3);
        solution1(start_row + plus_var, start_row + (plus_var * 2), start_col + plus_var, start_col + plus_var + plus_var, re/3);
        solution1(start_row + plus_var, start_row + (plus_var * 2), start_col + plus_var + plus_var, start_col + plus_var + plus_var +plus_var, re/3);
        
        solution1(start_row + (plus_var * 2), start_row + (plus_var * 3), start_col, start_col + plus_var, re/3);
        solution1(start_row + (plus_var * 2), start_row + (plus_var * 3), start_col + plus_var, start_col + plus_var + plus_var, re/3);
        solution1(start_row + (plus_var * 2), start_row + (plus_var * 3), start_col + plus_var + plus_var, start_col + plus_var + plus_var +plus_var, re/3);
    }
    
}

int main(){
    // N = 9
    input_data();
    solution1(0, N, 0, N, N);
    for(int i = 0; i < 3; i++){
        cout << results[i] << '\n';
    }
}
