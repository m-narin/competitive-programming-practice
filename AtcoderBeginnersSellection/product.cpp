/* 
aとbの席が偶数か奇数か

入力例
3 4

出力例
Even
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if(a * b % 2 == 0){
        cout << "Even";
    }else{
        cout << "Odd";
    }
}