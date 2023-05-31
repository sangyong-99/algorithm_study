//
//  20546.cpp
//  algorithm_study
//
//  Created by 신상용 on 2023/05/31.
//

#include <bits/stdc++.h>
using namespace std;

int cash, privious_price, current_price, jun, sung, jun_cash, sung_cash;
int stock_price[17][2];
int up_down = 0;
int countss = 0;

void jun_fun(int cash){
    for(int i = 1; i <= 14; i++){
        if (cash >= stock_price[i][0]){
            int stock_count = cash / stock_price[i][0];
            jun += stock_count;
            cash -= stock_price[i][0] * stock_count;
        }
    }
    jun_cash = cash;
    
}

void sung_fun(int cash){
    for(int i = 2; i <= 14; i++){
        if (stock_price[i][1] <= -3){
            int stock_count = cash / stock_price[i][0];
            sung += stock_count;
            cash -= stock_price[i][0] * stock_count;
        }
        else if (stock_price[i][1] >= 3){
            cash += stock_price[i][0] * sung;
            sung = 0;
        }
    }
    sung_cash = cash;
}

int main(){
    cin >> cash;
    cin >> privious_price;
    stock_price[1][0] = privious_price;
    cin >> current_price;
    stock_price[2][0] = current_price;
    if(privious_price < current_price) {
        up_down = 1;
        countss++;
    } else if (privious_price > current_price){
        up_down = -1;
        countss++;
    } else {
        up_down = 0;
        countss = 0;
    }
    stock_price[2][1] = up_down * countss;
    privious_price = current_price;
    
    
    for(int i = 3; i <= 14; i++){
        cin >> current_price;
        stock_price[i][0] = current_price;
        if (privious_price < current_price){                //증가할때
            if (up_down == 1){          //증가하고 있을때
                up_down = 1;
                countss++;
            } else {        //updown이 0이거나 -1
                up_down = 1;
                countss = 1;
            }
            
        } else if (privious_price == current_price){
            up_down = 0;
            countss = 0;
        } else if (privious_price > current_price){
            if (up_down == -1){
                up_down = -1;
                countss++;
            } else {
                up_down = -1;
                countss = 1;
            }
        }
        stock_price[i][1] = up_down * countss;
        privious_price = current_price;
    }
    jun_fun(cash);
//    cout << jun * stock_price[14][0] + jun_cash  << '\n';
    sung_fun(cash);
//    cout << sung * stock_price[14][0] + sung_cash << '\n';
    if ((jun * stock_price[14][0] + jun_cash) > (sung * stock_price[14][0] + sung_cash)){
        cout << "BNP";
    } else if ((jun * stock_price[14][0] + jun_cash) < (sung * stock_price[14][0] + sung_cash)){
        cout << "TIMING";
    } else {
        cout << "SAMESAME";
    }
}
