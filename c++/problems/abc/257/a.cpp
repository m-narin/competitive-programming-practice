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

    int num = X / N;
    int amari = X % N;

    char ans;

    if (amari == 0){
        ans = alpha[num-1];
    }else{
        ans = alpha[num];
    }

    cout << ans << endl;
    return 0;
}