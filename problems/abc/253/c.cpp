/* 
整数の多重集合Sのクエリ処理。
1 x : Sにxを1個追加する
2 x c : Sからxをmin(c,(Sに含まれるxの個数))個削除する
3 : (Sの最大値)-(Sの最小値)を出力する

入力例
8
1 3
1 2
3
1 2
1 7
3
2 2 3
3

出力例
1
5
4

*/

#include <bits/stdc++.h>
using namespace std;


// multisetは、順序付き多重集合(データを複数保持する)
// 追加、削除、検索の計算量はO(logN)
int main() {
    int n;
    cin >> n;

    multiset<int> S;

    for (int i = 0; i < n; i++){
        int query_number;
        cin >> query_number;

        if(query_number == 1){
            int x;
            cin >> x;
            S.insert(x);
        }else if (query_number == 2){
            int x, c;
            cin >> x >> c;

            // countは計算量が最悪の場合O(Q^2)となる
            // S.find(x)は計算量O(logN)で済む

            /*
            int count_x = S.count(x);
            for(int i = 0; i < min(c, count_x); i++){
                S.erase(S.find(x));
            }
            */

            // min(c,(Sに含まれるxの個数) は以下で表現できる
            // cが存在する限り and S.find(x)が存在する限り
            while(c-- and S.find(x) != S.end()){
                S.erase(S.find(x));
            }
        }else{
            cout << *S.rbegin() - *S.begin() << endl;
        }
        
    }
}