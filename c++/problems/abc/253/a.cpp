/* 
a,b,cが与えられる。bが中央値かどうか判定

入力例
5 3 2

出力例
Yes

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // 答え
    string res = "No";

    vector<int> values(3);

    values[0] = a;
    values[1] = b;
    values[2] = c;

    sort(values.begin(), values.end());

    if(values[1] == b){
        res = "Yes";
    }

    cout << res << endl;
}