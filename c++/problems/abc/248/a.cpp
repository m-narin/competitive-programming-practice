/* 
0~9の数字から成る長さ9の文字列。登場しない唯一の数字を出力

入力例
2 900

出力例
Yes

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    vector<int> num(10);
    for (int i = 0; i < 10; i++){

        // char型の数字は、連番のデータになるので引き算ができる
        int number = S[i] - '0';
        num[number]++;
    }

    int ans;
    for (int i = 0; i < 10; i++){
        if(num[i] == 0){
            ans = i;
        }
    }

    cout << ans << endl;
}