/*
単調増加、単調減少の数列にぴったり分割できるか

入力例
7
7 2 7 3 3 1 4

出力例
YES
2 単調増加数列の要素数
3 7 単調増加数列
5 単調減少数列の要素数
7 4 3 2 1 単調減少数列

※
分割できるか
単調増加数列の要素数
単調増加数列
単調減少数列の要素数
単調減少数列

入力例
5
0 1 2 3 4

出力例
YES
0

5
4 3 2 1 0 

*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a.at(i);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    vector<int> inc_seq(0);
    vector<int> dec_seq(0);
    
    dec_seq.push_back(a.at(0));
    
    vector<int> b(0);
    vector<int> c(0);
    
    for(int i=1; i<N; i++) {
        
        if(a.at(i) < dec_seq.back()){
            dec_seq.push_back(a.at(i));
        }else{
            b.push_back(a.at(i));
        }
        
    };
    
    if(b.size()!= 0){
        sort(b.begin(),b.end());

        // for(int i=0; i<b.size(); i++) cout << b.at(i);
        
        inc_seq.push_back(b.at(0));
        
        for(int i=1; i<b.size(); i++) {
            
            if(b.at(i) > inc_seq.back()){
                inc_seq.push_back(b.at(i));
            }else{
                c.push_back(b.at(i));
            }
        }
    }
    
    // for(int i=0; i<dec_seq.size(); i++) cout << dec_seq.at(i);
    
    // for(int i=0; i<c.size(); i++) cout << c.at(i);
    
    if(c.size() != 0){
        cout << "NO";
    }else{
        cout << "YES" << endl;
        cout << inc_seq.size() << endl;
        if (inc_seq.size() != 0){
            for(int i=0; i<inc_seq.size(); i++) cout << inc_seq.at(i) << " ";
        }
        cout << endl;
        cout << dec_seq.size() << endl;
        if (dec_seq.size() != 0){
            for(int i=0; i<dec_seq.size(); i++) cout << dec_seq.at(i) << " ";
        }
    }
    
}