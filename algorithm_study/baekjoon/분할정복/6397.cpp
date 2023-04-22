#include <bits/stdc++.h>
using namespace std;
string datas, dataa;
string result;
char form, prevs;
int n, m, indexss, option = 0;
int datas_array[250][250];
void input_intarray(){      //B문자열을 int 2차원 배열로 초기화
    int index = 0;
    for(int q = 0; q<n; q++)
        for(int w = 0; w<m; w++){
            datas_array[q][w] = datas[index] - '0';
            index++;
        }
}
void partition(int start_row, int end_row, int start_col, int end_col){
    if(start_row > end_row) {return;}
    if(start_col > end_col) {return;}
    int standard = datas_array[start_row][start_col];
    for(int qq = start_row; qq <= end_row; qq++){
        for(int ww = start_col; ww<=end_col; ww++){
            if(datas_array[qq][ww] != standard){
                result += 'D';
                goto parti;
            }
        }
    }
    result += to_string(standard);
    return;
parti:
    int mid_row = (ceil((double)(end_row - start_row + 1) / 2)) - 1 + start_row; //자를 인덱스 선택
    int mid_col = (ceil((double)(end_col - start_col + 1) / 2)) - 1 + start_col; //자를 인덱스 선택
    partition(start_row, mid_row, start_col, mid_col);
    partition(start_row, mid_row, mid_col+1, end_col);
    partition(mid_row+1, end_row, start_col, mid_col);
    partition(mid_row+1, end_row, mid_col+1, end_col);
}



void partition2(int start_row, int end_row, int start_col, int end_col){
    if(start_row > end_row) {return;}
    if(start_col > end_col) {return;}
    if(datas[indexss] != 'D'){
        int standard2 = datas[indexss] - '0';
        indexss++;
        for(int qq = start_row; qq <= end_row; qq++){
            for(int ww = start_col; ww<=end_col; ww++){
                datas_array[qq][ww] = standard2;
            }
        }
    }
    else if(datas[indexss] == 'D'){
        indexss++;
        int mid_row = (ceil((double)(end_row - start_row + 1) / 2)) - 1 + start_row; //자를 인덱스 선택
        int mid_col = (ceil((double)(end_col - start_col + 1) / 2)) - 1 + start_col; //자를 인덱스 선택
        partition2(start_row, mid_row, start_col, mid_col);
        partition2(start_row, mid_row, mid_col+1, end_col);
        partition2(mid_row+1, end_row, start_col, mid_col);
        partition2(mid_row+1, end_row, mid_col+1, end_col);
    }
}

int main() {
    while(true){
        if (option == 0) cin >> form;
        option = 0;
        if(form == '#'){        //#이 나올때 끝내기
            break;
        }
        cin >> n >> m;
        datas.clear();
        dataa.clear();
        if(form == 'D'){
            indexss = 0;    //datas 인덱스
            result.clear();
            while(true){
                cin >> dataa;
                if(dataa != "B" && dataa !="D" && dataa !="#"){
                    datas+=dataa;
                }
                else {
                    form = dataa[0];
                    option = 1;
                    break;
                };
            }
            partition2(0, n-1, 0, m-1);
            cout << 'B';
            cout.width(4);
            cout.fill(' ');
            cout << right << n;
            cout.width(4);
            cout.fill(' ');
            cout << right << m << '\n';
            for(int vv = 0; vv<n; vv++){
                for(int bb = 0; bb<m; bb++){
                    result += to_string(datas_array[vv][bb]);
                }
            }

            double str_length = result.length();
            for(int i = 0; i < (ceil((double)str_length / 50)); i++ ) {   //
                cout << result.substr(50*i, 50) << '\n';
            }
            
        }


        else{
            for(int dd = 0; dd < (ceil((double)n*m / 50)); dd++){
                cin >> dataa;
                datas += dataa;
            }
            input_intarray();       //string을 int 2차원 배열로 선언
            result.clear();     //result 지워줌
            partition(0, n-1, 0, m-1);
            cout << 'D';
            cout.width(4);
            cout.fill(' ');
            cout << right << n;
            cout.width(4);
            cout.fill(' ');
            cout << right << m << '\n';
            double str_length = result.length();
            for(int i = 0; i < (ceil((double)str_length / 50)); i++ ) {   //
                cout << result.substr(50*i, 50) << '\n';

            }
        }
    }
}



