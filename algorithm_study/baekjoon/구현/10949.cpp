//
//  10949.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/04/27.
//

#include <iostream>
using namespace std;

char datas[500][500]; int n;

void input_data(int n, int x, int y){
    if (n == 1){
        datas[x][y] = '*';
        return;
    }
    
    int len = 4 * (n - 1) + 1;
    
    for(int j = y; j < y + len; j++){
        datas[x][j] = '*';
        datas[x + len - 1][j] = '*';
    }
    for (int i = x; i < x + len; i++) {
            datas[i][y] = '*';
            datas[i][y + len - 1] = '*';
        }
     
        input_data(n - 1, x + 2, y + 2);
        return;
    
}

int main(){
    cin >> n;
    
    for(int i = 0; i < 4 * (n - 1) + 1; i++){
        for(int j = 0; j < 4 * (n - 1) + 1; j++){
            datas[i][j] = ' ';
        }
    }
    input_data(n, 0, 0);
    
    for(int i = 0; i < 4 * (n - 1) + 1; i++){
        for(int j = 0; j < 4 * (n - 1) + 1; j++){
            cout << datas[i][j];
        }
        cout << "\n";
    }
}
