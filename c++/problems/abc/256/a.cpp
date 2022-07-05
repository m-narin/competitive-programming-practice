/* 
2^Nを出力

入力例
3

出力例
8

*/


#include <bits/stdc++.h>
using namespace std;

int N, ans=1;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++){
        ans *= 2;
    }

    cout << ans << endl;
    return 0;
}