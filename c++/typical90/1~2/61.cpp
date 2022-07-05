/* 
カードの山札。Q個の操作
ti=1のとき、xiを一番上に入れる
ti=2のとき、xiを一番下に入れる
ti=3のとき、上からxi番目のカードを出力

入力例
6
1 2
1 1
2 3
3 1
3 2
3 3

出力例
1
2
3

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    int Q;
    cin >> Q;

    vector<int> v;

    for (int i = 0; i < Q; i++){
        int t, x;
        cin >> t >> x;

        if(t == 1){
            // イテレータを使って先頭に追加
            auto it = v.begin();
            v.insert(it,x); 
        }else if(t == 2){
            v.push_back(x);
        }else{
            cout << v[x-1] << endl;
        }
    }
}