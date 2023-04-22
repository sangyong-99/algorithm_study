//
//  main.cpp
//  coinmove
//
//  Created by 신상용 on 2022/10/01.
//

#include <bits/stdc++.h>
using namespace std;
ifstream fin("coinmove.inp");
ofstream fout("coinmove.out");
int T, P, K, S;
int abc, indexss = 0;
bool datas[11][8][1000001][8];
void reset(){
    for(int i = 2; i <= 10; ++i){       //배수설정
        for(int j = 3; j <= 7; ++j){     //움직일수있는거리
            for(int z = 1; z<=500000; ++z){     //시작하는 곳
                if(z % i == 0) continue;
                for(int x = 1; x <= j; ++x){       //몇칸 전에서 어디에서 왔는지
                    indexss = 0;
                    for(int dd = 1; dd <= j; ++dd){     //몇칸을 빼서 지는게 있으면 승리
                        abc = z - dd;
                        if(abc < 0) break;       //음수로 가면 pass
                        else if(dd == x) {continue;}
                        else if(abc > 0 && abc % i == 0) {continue;}
                        else if(datas[i][j][abc][dd] == 0){
                            datas[i][j][z][x] = 1;
                            indexss = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}
 

int main() {
    time_t start, end;
    double result;
    start = time(NULL); // 수행 시간 측정 시작

    reset();
    fin >> T;
    for(int i = 0; i < T; ++i){
        int index2 = 0;
        fin >> P >> K >> S;
        for(int k = 1; k <= K; ++k){
            if(S-k < 0) break;
            if((S-k) % P == 0) continue;
            else if(datas[P][K][S-k][k] == 0){
                fout << S-k << '\n';
                index2 = 1;
                break;
            }
        }
        if(index2 == 0) fout << -1 << '\n';
    }
    
    end = time(NULL); // 시간 측정 끝
    result = (double)(end - start);
    // 결과 출력
    printf("%f", result);
    return 0;
}
