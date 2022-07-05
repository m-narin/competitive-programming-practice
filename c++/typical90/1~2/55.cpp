/* 
N個の整数から5個選んだ積をPで割るとQ余るものは何通りあるか

入力例
6 7 1
1 2 3 4 5 6

出力例
1

*/

#include <bits/stdc++.h>
using namespace std;

// 計算量に関して、定数倍の見積もりも重要
// 全探索の場合、組み合わせを考えれば良いので、O(N^5)ではなく
// maxN 100の5乗= 10^10を5!でわって10^8になり、ACできる
// また、数字のオーバーフローに注意
// 10^9 * 10^9 一回で10^18になる 
// long longの最大値は、2^63-1 ≒ 9∗10^18 まで

int main() {

    // オーバーフローを見越してlong
    long long n, p, q;
    cin >> n >> p >> q;
    
    vector<long long> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            for (int k = 0; k < j; k++){
                for (int l = 0; l < k; l++){
                    for (int m = 0; m < l; m++){

                        // 積abcdeをpで割った余りは、
                        // 各あまりの積をpで割ったものと等しい
                        if(v[i] * v[j] % p * v[k] % p * v[l] % p * v[m] % p) == q{
                            count++ ;
                        }   

                        // 1LL*とすることで全体がlong longとして計算される            
                    }
                }
            }
        }
    }

    cout << count << endl;
}