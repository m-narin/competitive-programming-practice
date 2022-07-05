/* 
以下の操作を繰り返し、
・dream dreamer erase eraserのいずれかを追加する
Sと同じ文字列を作れるか

入力例
erasedream

出力例
YES

*/

#include <bits/stdc++.h>
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

// 方針
// 後ろから分解すると、各単語を区別できる
int main() {
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; i++)
        reverse(divide[i].begin(), divide[i].end());

    // 文字列を作れるか
    bool can_make = true;

    // 文字列の一致判定を繰り返す
    // 文字列の添え字は、一致した文字列の分だけ更新する
    for (int i = 0; i < S.size();){

        // 4この文字列のどれかでdivideできるか
        bool can_divide = false;
        for (int j = 0; j < 4; j++){
            string d = divide[j];

            // 部分文字列
            if(S.substr(i, d.size()) == d){
                can_divide = true;
                i += d.size();
            }
        }

        if(!can_divide){
            can_make = false;
            break;
        }

    }

    if(can_make){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}