/* 
大文字、小文字を含む。全ての文字列が異なるかどうか

入力例
AtCoder

出力例
Yes

*/

#include <bits/stdc++.h>
using namespace std;

// 方針
// 周期性があるので、各周期で条件を満たすときに移動距離を加算
int main() {
    string S;
    cin >> S;

    string res = "Yes";

    // 大文字を含むか

    bool has_upper = false;
    for (char c : S){
        if(isupper(c)){
            has_upper = true;
            break;
        }
    }
    if(!has_upper){
        res = "No";
    }

    // 小文字を含むか
    bool has_lower = false;
    for (char c : S){
        if(islower(c)){
            has_lower = true;
            break;
        }
    }
    if(!has_lower){
        res = "No";
    }

    // 相異なるか
    // setを使って、サイズが同じなら全て相異なると判定できる
    set<char> values;
    for (char c : S){
        values.insert(c);
    }

    if(values.size() != S.size()){
        res = "No";
    }

    cout << res << endl;
}