/* 
ユーザー名を登録
過去に重複する場合は、登録できない

入力例
5
e869120
atcoder
e869120
square1001
square1001

出力例
1
2
4

*/

#include <bits/stdc++.h>
using namespace std;


// 全探索は、N^2 <= 10^10でTLEとなる可能性がある
// 既に存在するかどうか、setを使う
int main() {

    int n;
    cin >>n;

    // 番号はindexで管理する
    vector<string> s(n);

    for (int i = 0; i < n; i++){
        cin >> s[i];
    }

    // キーだけのMapみたいなもの。順序付けされる。
    // 検索は二分探索できるので、O(logN)となる
    set<string> st;

    for (int i = 0; i < n; i++){
        
        // setの中身に合致する要素がなければ、初出と判定する
        if(st.count(s[i]) == 0){
            cout << i + 1 << endl;
        }
        st.insert(s[i]);
    }
}