//
//  main.cpp
//  path
//
//  Created by 신상용 on 2022/10/10.
//

#include <bits/stdc++.h>

using namespace std;
ifstream fin("path.inp");
ofstream fout("path.out");
int indexss, sum, x, y, c, m, n, k, right_data[110][110], down_data[110][110], arr[110][110], counts[110][110][250], costs[110][110][250];
vector<string> ss;      //경로저장

void reset(){
    fin >> m >> n >> k;
    for(int p=0; p<102; p++){memset(arr[p], 0, sizeof(int)*102);}
    for(int o = 0; o < k; o++){
        fin >> x >> y;
        arr[x][y] = -1;
    }
    for(int p = 0; p < m; p++){
        for(int o = 0; o < n-1; o++){
            fin >> x;
            right_data[p][o] = x;   //right 배열 초기화
        }
    }
    for(int p = 0; p < m - 1; p++){
        for(int o = 0; o < n; o++){
            fin >> x;
            down_data[p][o] = x;   //down 배열 초기화
        }
    }
    for(int ab = 0; ab < 102; ab++){            //costs초기화
        for(int bc = 0; bc < 102; bc++){
            memset(costs[ab][bc], 0, sizeof(int)*203);
        }
    }
    
    costs[0][0][0] = 0;
    counts[0][0][0] = 1;
}

void input_data(){
    indexss = 0; sum = 0;
    for(int i = 1; i < m; i++){     //첫번째 세로줄 초기화
        sum = sum + down_data[i - 1][0];
        if(arr[i][0] == -1){
            memmove(counts[i][0]+1,counts[i-1][0],sizeof(int)*201);
            counts[i][0][0] = 0;
            indexss++;
            costs[i][0][indexss] = sum;
        }
        else{
            memmove(counts[i][0], counts[i-1][0], sizeof(int)*201);
            costs[i][0][indexss] = sum;
        }
    }
    indexss = 0; sum = 0;
    for(int i = 1; i < n; i++){     //가로줄 초기화
        sum = sum + right_data[0][i - 1];
        if(arr[0][i] == -1){
            memmove(counts[0][i]+1,counts[0][i-1],sizeof(int)*201);
            counts[0][i][0] = 0;
            indexss++;
            costs[0][i][indexss] = sum;
        }
        else{
            memmove(counts[0][i], counts[0][i-1], sizeof(int)*201);
            
            costs[0][i][indexss] = sum;
        }
    }
}

void solution(){
    for(int i = 1; i < m; i++){     //행
        for(int j = 1; j < n; j++){     //열
            for(int zaz = 0; zaz <= k; zaz++){               //범위를 k로 줄일수 있지 않은가?
                counts[i][j][zaz] = (counts[i-1][j][zaz] + counts[i][j-1][zaz]) % 100000;        //5자리수 입출력 처리 해야됨
                
                int left = -1, up = -1;
                if(costs[i][j-1][zaz] != 0)   left = costs[i][j-1][zaz] + right_data[i][j-1];
                if(costs[i-1][j][zaz] != 0)   up = costs[i-1][j][zaz] + down_data[i-1][j];
                if(left != -1 && up != -1)  costs[i][j][zaz] = min(left, up);
                else if(left == -1 && up == -1) costs[i][j][zaz] = 0;
                else if(left == -1) costs[i][j][zaz] = up;
                else if(up == -1) costs[i][j][zaz] = left;
                
            }
            if(arr[i][j] == -1){
                memmove(counts[i][j]+1,counts[i][j],sizeof(int)*201);
                counts[i][j][0] = 0;
                
                memmove(costs[i][j]+1,costs[i][j],sizeof(int)*201);
                costs[i][j][0] = 0;
            }
            
        }
    }
    
}

void path_data(){
    for(int kkk = 0; kkk <= k; kkk++){
        int sese = (counts[m - 1][n - 1][kkk]) % 100000;
        if(sese != 0){
            int zzz = kkk;
            int r_index, c_index;
            ss.clear();
            r_index = m-1; c_index = n-1;
            while(r_index >= 0 && c_index >= 0){
                if(arr[r_index][c_index] == -1){
                    if(costs[r_index][c_index - 1][zzz-1] == costs[r_index][c_index][zzz] - right_data[r_index][c_index-1]){
                        ss.push_back("(" + to_string(r_index) + "," + to_string(c_index) + ")");
                        c_index--;
                        zzz--;
                    }
                    else if(costs[r_index-1][c_index][zzz-1] == costs[r_index][c_index][zzz] - down_data[r_index-1][c_index]){
                        ss.push_back("(" + to_string(r_index) + "," + to_string(c_index) + ")");
                        r_index--;
                        zzz--;
                    }
                    
                }
                else{
                    if(costs[r_index][c_index - 1][zzz] == costs[r_index][c_index][zzz] - right_data[r_index][c_index-1]){
                        ss.push_back("(" + to_string(r_index) + "," + to_string(c_index) + ")");
                        c_index--;
                    }
                    else if(costs[r_index-1][c_index][zzz] == costs[r_index][c_index][zzz] - down_data[r_index-1][c_index]){
                        ss.push_back("(" + to_string(r_index) + "," + to_string(c_index) + ")");
                        r_index--;
                    }
                }
            }
            reverse(ss.begin(), ss.end());
            fout << "k:" << kkk << " count:" << sese << " cost:" << costs[m-1][n-1][kkk] << '\n';
            
            for(int abc = 0; abc < ss.size(); abc++){
                if(abc == (ss.size()-1)) fout << ss[abc] << '\n';
                else fout << ss[abc] << "->";
            }
        }
    }
}

int main() {
    fin >> c;
    for(int z = 1; z <= c; z++){
        reset();
        input_data();
        solution();
        fout << "Test Case No:" << z << '\n';
        path_data();
        fout << '\n';
    }
}





