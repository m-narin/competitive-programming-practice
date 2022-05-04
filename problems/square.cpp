/*
与えられた2つの長方形を組み合わせて
正方形を作れるかどうかを判定


入力例
3
2 3
3 1
3 2
1 3
3 3
1 3

出力例
Yes
Yes
No

*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int loop = 0 ; loop < t ; ++loop){
        int a1,a2,b1,b2;
        cin >> a1 >> b1;
        cin >> a2 >> b2;
        
        string ans = "YES"; //YESと仮定すると…
    
        int L = max(a1,b1); //#正方形の長さは、a1,b1の内で大きいほう

        //ここでもし、max(a2,b2)がLと等しくないのなら、ansを"NO"にする。
        if (max(a2,b2) != L){
            ans = "NO";
        }
        //ここでもし、min(a1,b1)+min(a2,b2) がLと等しくないのなら、ansを"NO"にする。
        if ( min(a1,b1)+min(a2,b2) != L ){
            ans = "NO";
        }
        cout << ans << '\n'; //ansを出力
    }
}