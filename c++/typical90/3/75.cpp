/* 
整数Nが書かれたボールが一個ある。
整数xが書かれたボールを叩くと以下の操作が行われる
xが素数でない場合、ab=xを満たすa,bが書かれたボールが追加される
xが素数の場合、何も起こらない
魔法を使うと、全てのボールを叩くことができる。
全てのボールをに書かれている数を素数にするには、
最小で何回の操作が必要か？


入力例
42

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;

// O(√N)で素因数分解する
// 分割していくので、2^k >= 素因数分解した因子数
// を満たす最小のkが答え

long long N;

// 与えられた数を素因数分解した配列を生成
vector<long long> prime_factors(long long N){
    long long rem = N;
    vector<long long> p;
    for (long long i = 2; i * i <= N; i++){
        while(rem % i == 0){
            rem /= i;
            p.push_back(i);
        }
    }
    if(rem != 1LL){
        p.push_back(rem);
    }
    return p;
}

int main() {
    cin >> N;

    int Answer = 0;
    vector<long long> vec = prime_factors(N);

    // (1 << i)は1をibit左シフトしたもの
    // つまり、2^i乗の数字を表す
    // (1 << 2) = 2^2 = 4 
    // 2進法で表すと、100
    for (int i = 0; i <= 20; i++){
        if((1 << i) >= vec.size()){
            Answer = i;
            break;
        }
    }
    cout << Answer << endl;
    return 0;
}