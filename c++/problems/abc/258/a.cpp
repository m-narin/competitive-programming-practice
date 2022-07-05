/*
21時ちょうどからK分後の時刻をHH:MMの形式で出力

入力例
63

出力例
22:03

*/

#include <bits/stdc++.h>
using namespace std;

int K;

int main()
{

    cin >> K;

    int h = K / 60 + 21;

    int m = K % 60;

    cout << h << ":";

    // 0埋め
    cout << setw(2) << setfill('0') << m << endl;

    // printf("%d:%02d", H, M);

    return 0;
}