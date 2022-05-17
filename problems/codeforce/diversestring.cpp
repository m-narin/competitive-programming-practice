/*
文字列がアルファベット順で連続した文字しか含まず、
同じ文字が2回以上出現しないものを判定


入力例
8
fced
xyz
r
dabcef
az
aa
bad
babc

出力例
Yes
Yes
Yes
Yes
No
No
No
No

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        
        string output = "No";
        
        // 重複無し&ソートされた集合を作る
        set<char> st;
        for(int j = 0; j < str.size(); j++){
            st.insert(str[j]);
        }
        
        // 重複なし&アルファベット順のとき、Yesになる
        char fst = *st.begin();
        char lst = *prev(st.end());
        int num_of_kind = lst - fst + 1;
        
        if(st.size() == str.size() && num_of_kind == str.size()){
            output = "Yes";
        }
        
        /*
        for(auto x : st) {
            cout << x << " ";     // 要素を順に表示
        }
        cout << endl;
        */
        
        cout << output << endl;
    }
}