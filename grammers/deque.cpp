/* 
カードの山札。Q個の操作
ti=1のとき、xiを一番上に入れる
ti=2のとき、xiを一番下に入れる
ti=3のとき、上からxi番目のカードを出力

入力例
6
1 2
1 1
2 3
3 1
3 2
3 3

出力例
1
2
3

*/

#include <bits/stdc++.h>
using namespace std;

// dequeを使うと便利
// 動的配列クラスで、両端の要素追加削除をO(1)でできる
int main() {

    int Q;
    cin >> Q;

    deque<int> deq;

    for (int i = 0; i < Q; i++){
        int t, x;
        cin >> t >> x;

        if(t == 1){
            deq.push_front(x);
        }else if(t == 2){
            deq.push_back(x);
        }else{
            cout << deq[x-1] << endl;
        }

        // 要素の削除は以下のように書く
        /*
            deq.pop_front();
            deq.pop_back();
        */
    }

    for(int i==1; i<Q; i++){
        
    }
}