/* 
1以上N以下の整数の内、
10進法で各桁の和がA以上B以下であるものの総和

入力例
20 2 5

出力例
84

*/

#include <bits/stdc++.h>
using namespace std;

// 各桁の和を求める関数
/*
834 を 10 で割った余りは 4 -> 答えに加算
834 を 10 で割って 83
83 を 10 で割った余りは 3 -> 答えに加算
83 を 10 で割って 8
8 を 10 で割った余りは 8 -> 答えに加算
8 を 10 で割って 0
0 なので break
*/
int findSumOfDigits(int n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int total = 0;
    for (int i = 0; i <= n; i++){

        int sum = findSumOfDigits(i);

        if(sum >= a && sum <= b){
            total += i;
        }
    }

    cout << total << endl;
}