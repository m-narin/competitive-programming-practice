/* 
文字列中にABCはいくつあるか

入力例
10
ZABCDBABCQ

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    for (int i = 0; i < n-2; i++){
        if(s.substr(i,3) == "ABC"){
            count++;
        }
    }

    cout << count << endl;
}