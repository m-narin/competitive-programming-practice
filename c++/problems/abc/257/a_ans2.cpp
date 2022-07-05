/* 

入力例

出力例

*/


#include <bits/stdc++.h>
using namespace std;

int N, X;
int A[10009];
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {

    cin >> N >> X;

    int num = (X-1) / N;

    char ans = 'A' + num;

    cout << ans << endl;
    return 0;
}