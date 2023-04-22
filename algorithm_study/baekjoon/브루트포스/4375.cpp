//
//  4375.cpp
//  Test
//
//  Created by 신상용 on 2022/11/22.
//

#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
    while(cin >> N){
        int countss = 1, dkdk = 1;
        for(;;countss++){
            if(dkdk % N == 0) break;
            else{
                dkdk = dkdk * 10 + 1;
                
                dkdk %= N;
            }
        }
        cout << countss << '\n';
    }
}
