/* 
1が書かれた数

入力例
101

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    int count = 0;
    for(char s : str){
        if (s == '1'){
            count++;
        }
    }

    cout << count << endl;
}