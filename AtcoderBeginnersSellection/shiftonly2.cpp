/* 
整数が全て偶数のとき、2で何回割れるか

入力例
3
8 12 40

出力例
2

*/

#include <iostream>
using namespace std;

const int INF = 10000000;   // 十分大きな値に

int N;
int A[210];         // 最大 200 個なので余裕を持って 210 に

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    // 2で割り切れる回数の最小値がボトルネック。これが答え
    int res = INF;

    for (int i = 0; i < N; ++i) {
        int count = 0;  

        // 各数字に関して、偶数の間2で割り続ける→要素を更新
        while (A[i] % 2 == 0) {
            A[i] /= 2;
            ++count;
        }

        // 最小値を更新
        if (res > count) res = count;
    }

    cout << res << endl;
}