/* 
文字列とその得点
文字列の初出の中でもっとも得点が高い提出は何番目か

入力例
5
aaa 9
bbb 10
ccc 10
ddd 10
bbb 11

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 番号はindexで管理する
    vector<string> s(n);
    vector<int> t(n);

    for (int i = 0; i < n; i++){
        cin >> s[i] >> t[i];
    }

    // 各番号の提出がオリジナルか判定する
    vector<bool> orig(n);
    set<string> st;

    for (int i = 0; i < n; i++){
        
        // setの中身の合致する要素数をカウント
        if(st.count(s[i]) == 0){
            orig[i] = true;
        }
        st.insert(s[i]);
    }

    int score = -1, ans = -1;

    for (int i = 0; i < n; i++){
        if(!orig[i]) continue;

        if(score < t[i]){
            score = t[i];
            ans = i + 1;
        }
    }
    cout << ans << endl;
}
