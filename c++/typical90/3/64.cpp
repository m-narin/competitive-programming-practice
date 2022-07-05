/* 
N個の区画、Q回の地殻変動が起こる
i回目の地殻変動では、L~Rの標高がVだけ変化する。
各区画の不便さを求めよ。
不便さは隣り合う区画の標高の差の合計。

入力例
3 3
1 2 3
2 3 1
1 2 -1
1 3 2

出力例
3
4
4

*/

// 配列全要素を書き換えていくと、O(N^2)でTLE
// 隣接区画の標高差なので、階差Bを考える
// 不便さは階差配列の絶対値の和
// L~Rの区画の標高がV増えた時、
// B(L-1)が+V, B(R)が-Vになる
// 不便さをO(1)で求められるので、計算量はO(N+Q)

#include <bits/stdc++.h>
using namespace std;

long long N, Q, inconvenience;
long long A[100009], L[100009], R[100009], V[100009], B[100009];

int main() {
    cin >> N >> Q;

    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }

    for (int i = 1; i <= Q; i++){
        cin >> L[i] >> R[i] >> V[i];
    }

    for (int i = 1; i <= N-1; i++){
        B[i] = A[i + 1] - A[i];
        inconvenience += abs(B[i]);
    }

    for (int i = 1; i <= Q; i++){
        long long mae = abs(B[L[i] - 1]) + abs(B[R[i]]);
        if(L[i] >= 2){
            B[L[i] - 1] += V[i];
        }
        if(R[i] <= N-1){
            B[R[i]] -= V[i];
        }
        long long ato = abs(B[L[i] - 1]) + abs(B[R[i]]);

        inconvenience += (ato - mae);
        cout << inconvenience << endl;
    }
    return 0;
}