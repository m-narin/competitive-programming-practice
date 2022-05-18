/* 
500円玉をK枚。総額がX円以上か？

入力例
2 900

出力例
Yes

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, x;
    cin >> k >> x;

    if(500 * k >= x){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}