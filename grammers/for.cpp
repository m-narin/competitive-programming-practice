/* 

入力例を配列に入れて出力

入力例
5
2 4 6 6 6
one two three four five

出力例
2 4 6 6 6
one two four five

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    // 要素数を取得
    int n;
    cin >> n;

    // 数字配列
    vector<int> num_list(n);

    // 数字配列を作成
    for (int i = 0; i < n; i++){
        cin >> num_list.at(i);
    }

    // 数字配列を出力
    for(int x : num_list){
        cout << x << " ";
    }

    cout << endl;

    // 文字配列
    // 文字1文字はchar型 ''で囲む
    vector<string> str_list(n);

    // 文字配列を作成
    for (int i = 0; i < n; i++){
        cin >> str_list.at(i);
    }

    // 文字配列を出力
    for(string c : str_list){

        if(c == "three"){
            continue;
        }
        cout << c << " ";
    }
}

