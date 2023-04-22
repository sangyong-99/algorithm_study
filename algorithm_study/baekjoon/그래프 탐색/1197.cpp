//
//  1197.cpp
//  baekjoon
//
//  Created by 신상용 on 2023/01/02.
//

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ifstream fin("mst.inp");
ofstream fout("mst.out");
vector<tuple<ll, ll, ll, ll, ll>> datas;
ll n, m, u, v, w, result1, indexss, node_count, p, q;
vector<ll> result2;
bool compares(tuple<ll, ll, ll, ll, ll> &v1, tuple<ll, ll, ll, ll, ll> &v2){
    if(get<1>(v1) == get<1>(v2)) return get<0>(v1) < get<0>(v2);
    return get<1>(v1) < get<1>(v2);
}
void output(bool pp, ll s = 0){
    if(pp)
        fout << "Tree edges by Kruskal algorithm: " << result1 << "\n";
    else
        fout << "Tree edges by Prim algorithm with starting vertex " << s << ": " << result1 << "\n";
    for(ll i = 0; i < result2.size(); i++)
        fout << result2[i] << "\n";
}
void reset(bool pp, ll s = 0){
    result1 = 0;
    node_count = 1;
    result2.clear();
    for(ll i = 0; i < datas.size(); i++)
        if(pp) get<4>(datas[i]) = i;
        else {get<4>(datas[i]) = 0; get<4>(datas[s]) = 1;}
}
ll find(ll i){
    indexss = i;
    while(get<4>(datas[indexss]) != indexss)
        indexss = get<4>(datas[indexss]);
    return indexss;
}
void merge(ll p, ll q){
    p = find(p);
    q = find(q);
    get<4>(datas[q]) = p;
}
void save_fix(bool pp, ll i, ll p = 0, ll q = 0){
    result1 += get<1>(datas[i]);
    result2.push_back(get<0>(datas[i]));
    node_count++;
    if(pp) merge(p, q);
    else get<4>(datas[(get<3>(datas[i]))]) = get<4>(datas[(get<2>(datas[i]))]) = 1;  //node 색칠
}
void kruskal(){
    reset(true);
    while(true){
        if(node_count == n) break;
        for(ll i = 0; i < m; i++){
            p = find(get<2>(datas[i]));
            q = find(get<3>(datas[i]));
            if(p != q) save_fix(true, i, p, q);
        }
    }
    output(true);
}
void prim(ll s){
    reset(false, s);
    while(true){
        if(node_count == n) break;
        for(ll i = 0; i < m; i++)
            if((get<4>(datas[(get<3>(datas[i]))]) == 0 && get<4>(datas[(get<2>(datas[i]))]) == 1) || (get<4>(datas[(get<2>(datas[i]))]) == 0 && get<4>(datas[(get<3>(datas[i]))]) == 1)){
                save_fix(false, i);
                break;
            }
    }
    output(false, s);
}
int main(){
    fin >> n >> m;
    for(ll i = 0; i < m; i++, indexss++){
        fin >> u >> v >> w;
        datas.push_back(make_tuple(indexss, w, u, v, 0));
    }
    sort(datas.begin(), datas.end(), compares);
    kruskal();  prim(0);    prim(n/2);  prim(n-1);
}

