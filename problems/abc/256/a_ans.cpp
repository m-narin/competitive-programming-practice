/* 
2^Nを出力

入力例
3

出力例
8

*/


#include <bits/stdc++.h>
using namespace std;

int N;

// 2の累乗はbitシフトが使える

int main() {
    cin >> N;
    cout << (1 << N) << endl;
    return 0;
}