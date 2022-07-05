/* 
N人、クラス2組、学籍番号i番のクラスと点数が与えられる
1,2組それぞれに関して、学籍番号Li~Rjの点数の合計を出力

入力例
7
1 72
2 78
2 94
1 23
2 89
1 40
1 75
1
2 6

出力例
63 261

*/

#include <bits/stdc++.h>
using namespace std;

// c組、n番目までの累積和を計算
/*
int calculate_comulative_sum(vector<int> &C,vector<int> &P,int c,int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if(C[i] == c){
            result += P[i];
        }
    }
    return result;
}
*/

int main() {
    int n;
    cin >> n;

    // 入力
    vector<int> C(n+1);
    vector<int> P(n+1);
    for (int i = 1; i <= n; i++){
        cin >> C[i];
        cin >> P[i];
    }

    int q;
    cin >> q;

    vector<int> L(q+1);
    vector<int> R(q+1);
    for (int i = 1; i <= q; i++){
        cin >> L[i];
        cin >> R[i];
    }

    // 方針 2重ループはO(NQ) >= 10^10でTLEになる
    // i番目までの累積和を計算する
    // するとO(N+Q)になる

    vector<int> comuative_sum_of_1(n + 1);
    vector<int> comuative_sum_of_2(n + 1);

    for(int i = 1; i <= n; i++){
        comuative_sum_of_1[i] = comuative_sum_of_1[i - 1];
        comuative_sum_of_2[i] = comuative_sum_of_2[i - 1];
        if(C[i] == 1){
            comuative_sum_of_1[i] += P[i];
        }
        if(C[i] == 2){
            comuative_sum_of_2[i] += P[i];
        }
    }


    // 計算
    for(int i = 1; i <= q; i++){
        int ans1 = comuative_sum_of_1[R[i]] - comuative_sum_of_1[L[i] - 1];
        int ans2 = comuative_sum_of_2[R[i]] - comuative_sum_of_2[L[i] - 1];
        cout << ans1 << " " << ans2 << endl;
    }
}