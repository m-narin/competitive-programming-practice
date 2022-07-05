/* 
Alice, Bobは、数が書かれたN枚のカードを交互に取っていく
大きい数字から順に取っていったときのAliceの得点-Bobの得点を求める

入力例
3
2 7 4

出力例
5

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++){
        cin >> cards.at(i);
    }

    // 降順にソート
    sort(cards.begin(), cards.end());
    reverse(cards.begin(), cards.end());

    // 以下の方法でも降順ソートになる
    // sort(cards.begin(), cards.end(), greater<int>());

    int alice_score = 0;
    int bob_score = 0;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            alice_score += cards.at(i);
        }else{
            bob_score += cards.at(i);
        }
    }

    cout << alice_score - bob_score << endl;
}