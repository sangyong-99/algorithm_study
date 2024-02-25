//
//  prac.cpp
//  algorithm_study
//
//  Created by 신상용 on 2/24/24.
//

#include <bits/stdc++.h>

using namespace std;

struct Datas {
    char ID;
    vector<int> CLASS;
    int size = 16;
    bool lock = false;
};

void solution(vector<string> text, vector<pair<string, int>> command) {
    vector<Datas> datass;
    for(int i = 0; i < text.size(); i++) {
        char id;
        int number;
        vector<int> classes;
        istringstream ii(text[i]);
        ii >> id;
        while (ii >> number) {
            classes.push_back(number);
        }
        Datas data;
        data.ID = id;
        data.CLASS = classes;
        datass.push_back(data);
    }
    
    
    for(pair<string, int> each_command: command) {
        string id_class = each_command.first;
        if (id_class[0] == '.') {
            
            for(Datas& dd: datass) {
                
                for(int ii: dd.CLASS) {
                    if (ii == stoi(id_class.substr(1)) && !dd.lock) {
                        dd.size = each_command.second;
                        }
                }
            }
        }
        else {
            for(Datas& dd: datass) {
                if (dd.ID == id_class[1]) {
                    dd.size = each_command.second;
                    dd.lock = true;
                }
            }
        }
    }
    cout << datass[0].size << endl;
    cout << datass[1].size << endl;
    
}

int main() {
    vector<string> text = {"f 5 6 10", "d 3 10 9"};
    vector<pair<string, int>> command = {{".3", 10}, {"#f", 9}, {"#d", 3}, {".10", 1}};
    
    solution(text, command);
    
}


