/* 
N個のクラスがありi番目はレーティングAiを対象としている
Q人の生徒のレーティングとクラスのレーティングの絶対値の
最小値を出力する

入力例
4
4000 4400 5000 3200
3
3312
2992
4229

出力例
112
208
171

*/

#include <bits/stdc++.h>
using namespace std;

// ソートして二分探索
// lower_boundはソートされた配列に使う

const int INF = 2000000000;

int main() {

    int N;
	cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int Q;
    cin >> Q;

    vector<int> B(Q);

    for (int i = 0; i < Q; i++){
        cin >> B[i];
    }

    for (int i = 0; i < Q; i++){

        // B[i]以上のレーティングクラスと、
        // その一つ下のレーティングクラスのうち小さい方
        // lower_boundはイテレータを返す
        // 存在しなかった場合、右端のイテレータを返す
        // 左端になったときの条件に注意

        int pos1 = lower_bound(A.begin(), A.end(), B[i]) - A.begin();

        int diff1 = INF;
        int diff2 = INF;

        diff1 = abs(A[pos1] - B[i]);
        if(pos1 >= 1){
            diff2 = abs(A[pos1-1] - B[i]);
        }
        cout << min(diff1, diff2) << endl;
    }
}