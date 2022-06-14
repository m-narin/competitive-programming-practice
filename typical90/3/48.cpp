/* 
N問の問題がある。
1分かけると部分点が得られ、もう1分かけると満点が得られる。
部分点は満点の半分より大きい。
K分間で得られる合計得点の最大値を求めよ。

入力例
4 3
4 3
9 5
15 8
8 6

出力例
21

*/

#include <bits/stdc++.h>
using namespace std;

// 上界を見積もって貪欲法
// 各手段を降順でソートして、降順に要素を足したものが上界値

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> vec(2*n);

    for (int i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        vec.push_back(b);
        vec.push_back(a - b);
    }

    long long ans = 0;

    // 計算量はO(NlogN)
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    for (int i = 0; i < k; i++){
        ans += vec[i];
    }

    cout << ans << endl;
}