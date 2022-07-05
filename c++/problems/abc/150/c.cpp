/* 
大きさNの順列の辞書順でa番目に小さく、
b番目に小さいものの|a-b|

入力例
3
1 3 2
3 1 2

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> P(n);
    vector<int> Q(n);

    for (int i = 0; i < n; i++){
        cin >> P[i];
    }

    for (int i = 0; i < n; i++){
        cin >> Q[i];
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        v[i] = i+1;
    }

    int a;
    int b;
    int idx = 0;

    // 全ての順列を生成

    do{
        bool p_same = true;
        bool q_same = true;
        for (int i = 0; i < n; i++){
            if(v[i] != P[i]){
                p_same = false;
            }

            if(v[i] != Q[i]){
                q_same = false;
            }
        }

        if(p_same){
            a = idx;
        }

        if(q_same){
            b = idx;
        }

        idx++;

    } while (next_permutation(v.begin(), v.end()));

    int ans = abs(a - b);

    cout << ans << endl;
}