/* 
大文字、小文字を含む。全ての文字列が異なるかどうか

入力例
AtCoder

出力例
Yes

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool big = false, small = false;

    for(int i = 0; i < s.size(); i++){
        if(isupper(s[i])){
            big = true;
        }else{
            small = true;
        }
    }

    bool diff = true;

    for(int i = 0; i < s.size(); i++){
        for(int j = i + 1; j < s.size(); j++){
            if(s[i] == s[j]) diff = false;
        }
    }

    if(big && small && diff){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}