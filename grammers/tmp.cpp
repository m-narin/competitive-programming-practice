/* 
配列の隣り合う要素のうち、
値が等しいものが存在するなら"YES"を、
存在しなければ"NO"を出力してください。

入力例
5 3 3 1 4

出力例
YES

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> data(5);
    for (int i = 0; i < 5; i++) {
        cin >> data.at(i);
    }

    string ans = "NO";
    for (int i = 0; i < data.size() - 1; i++){
        if(data.at(i) == data.at(i+1)){
            ans = "YES";
        }
    }

    cout << ans << endl;
}