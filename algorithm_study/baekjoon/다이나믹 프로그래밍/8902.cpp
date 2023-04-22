//
//  main.cpp
//  Color Length
//
//  Created by 신상용 on 2022/10/28.
//
#define MAX 10000000000
#include <bits/stdc++.h>
using namespace std;
ifstream fin("color.inp");
ofstream fout("color.out");
string first, second;
long long T, dp[5010][5010], first_a[30], first_b[30], second_a[30], second_b[30];
long long solution(int position, int first_position, int second_position) {
    if(first[first_position] == 0 && second[second_position] == 0) return 0;
    long long &value = dp[first_position][second_position];
    if(value != -1) return value;
    long long aPick = first[first_position] - 'A';
    long long bPick = second[second_position] - 'A';
    value = MAX;
    if(first[first_position]) {
        if(first_a[aPick] == first_position && (second_a[aPick] == -1 || second_a[aPick] >= second_position)) {
            (first_b[aPick] == first_position && second_a[aPick] == -1)?value = min(value, solution(position+1, first_position+1, second_position)):value = min(value, -position + solution(position+1, first_position+1, second_position));
        }
        else if(first_b[aPick] == first_position && (second_b[aPick] == -1 || second_b[aPick] < second_position)) {
            (first_a[aPick] == first_position && second_b[aPick] == -1)?value = min(value, solution(position+1, first_position+1, second_position)):value = min(value, position + solution(position+1, first_position+1, second_position));
        }
        else value = min(value, solution(position+1, first_position+1, second_position));
    }
    if(second[second_position]) {
        if(second_a[bPick] == second_position && (first_a[bPick] == -1 || first_a[bPick] >= first_position)) {
            (second_b[bPick] == second_position && first_a[bPick] == -1)?
                value = min(value, solution(position+1, first_position, second_position+1))
            :
                value = min(value, -position + solution(position+1, first_position, second_position+1));
        }
        else if(second_b[bPick] == second_position && (first_b[bPick] == -1 || first_b[bPick] < first_position)) {
            (second_a[bPick] == second_position && first_b[bPick] == -1)?value = min(value, solution(position+1, first_position, second_position+1)):value = min(value, position + solution(position+1, first_position, second_position+1));
        }
        else value = min(value, solution(position+1, first_position, second_position+1));
    }
    return value;
}
void reset(){
    memset(first_a, -1, sizeof(first_a));
    memset(first_b, -1, sizeof(first_b));
    memset(second_a, -1, sizeof(second_a));
    memset(second_b, -1, sizeof(second_b));
    memset(dp, -1, sizeof(dp));
}
void input_data(){
    fin >> first >> second;
    for(int i=0; first[i]; i++) {
        if(first_a[first[i]-'A'] == -1) first_a[first[i]-'A'] = i;
        first_b[first[i]-'A'] = i;
    }
    for(int i=0; second[i]; i++) {
        if(second_a[second[i]-'A'] == -1) second_a[second[i]-'A'] = i;
        second_b[second[i]-'A'] = i;
    }
}
int main() {
    fin >> T;
    for(int i = 0; i < T; i++) {
        reset();
        input_data();
        fout << solution(0, 0, 0) << '\n';
    }
    return 0;
}
