//
//  contact.cpp
//  secret_contact
//
//  Created by 신상용 on 2022/11/19.
//

#include <bits/stdc++.h>
using namespace std;
ifstream fin("contact.inp");
ofstream fout("contact.out");
#define INF 1000000000
int T, N, M, K, graph[600][600], dij[600], path[600][600], visited[600];
int start, endss, length, indexss, indexss2, mot1, mot2, mot3, node_1, node_2;
void input_data(){
    for(int j = 0; j < N; j++){
        for(int z = 0; z < N; z++){
            graph[j + 1][z + 1] = INF;
            node_1 = node_2 = INF;
        }
    }
    for(int j = 0; j <= N; j++){
        graph[j + 1][j + 1] = 0;
    }
    for(int j = 0; j < M; j++){
        fin >> start >> endss >> length;
        graph[start][endss] = length;
        graph[endss][start] = length;
    }
}
void solution2(){
    indexss = 0;
    while(true){
        if(path[endss][indexss] == -1) break;
        mot1 = path[endss][indexss];
        indexss2 = length - graph[mot1][endss];
        if(indexss2 < 0){
            mot2 = mot1; mot3 = endss;
            if(mot2 > mot3)swap(mot2, mot3);
            if(node_1 > mot2) {node_1 = mot2; node_2 = mot3;}
            else if(node_1 == mot2 && node_2 > mot3)
                node_2 = mot3;
        }
        else if(indexss2 > 0){
            length = indexss2; endss = mot1;
            solution2();
        }
        else{
            if(node_1 > mot1){node_1 = mot1; node_2 = mot1;}
            else if(node_1 == mot1 && node_2 > mot1)
                node_2 = mot1;
        }
        indexss++;
    }
}
void solution(){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            path[i][j] = -1;
        }
    }
    for(int i = 1; i <= N; i++){
        visited[i] = 0;
        path[i][0] = -1;
        indexss2 = dij[i] = graph[start][i];
        if(indexss2 > 0 && indexss2 < INF){
            path[i][0] = start;
        }
    }
    visited[start] = 1;
    for(int i = 0; i < N; i++){
        mot1 = INF;
        for(int j  = 1; j <= N; j++){
            if(visited[j] == 1)continue;
            if(dij[j] < mot1){mot1 = dij[j]; mot2 = j;}
        }
        visited[mot2] = 1;
        for(int j = 1; j <= N; j++){
            if(visited[j] == 1 || graph[mot2][j] == INF) continue;
            indexss = dij[mot2] + graph[mot2][j];
            if(dij[j] == indexss){
                for(int z = 1; ; z++){
                    if(path[j][z] == -1){
                        path[j][z] = mot2;
                        break;
                    }
                }
            }
            else if(dij[j] > indexss){
                dij[j] = indexss;
                path[j][0] = mot2;
            }
        }
    }
    length = (double)dij[endss]/2;
    solution2();
}
int main(void){
    fin >> T;
    for(int i = 0; i < T; i++){
        fin >> N >> M >> K;
        input_data();
        for(int j = 0; j < K; j++){
            fin >> start >> endss;
            solution();
            fout << node_1 << " " << node_2 << endl;
        }
    }
}
