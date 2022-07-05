/* 
4つのマスがある。整数P=0
次の操作を行う
①マス0に駒を一つ置く
②マス上の全ての駒を番号がAi大きいマスに進める
→移動先のマスが無い場合、Pに取り除いた駒を加算する
最終的なPを出力

入力例
4
1 1 3 2

出力例
3

*/


#include <bits/stdc++.h>
using namespace std;

int N, P = 0;
int A[109], masu[4];

int main() {

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++){
        masu[i] = 0;
    }


    for (int i = 0; i < N; i++){

        // マス0に駒を置く
        masu[0] = 1;

        // マス上の全ての駒をAiだけ進める
        for (int j = 3; j >= 0; j--){
            if(masu[j] == 1){
                masu[j] = 0;
                if(j + A[i] >= 4){
                    P++;
                }else{
                    masu[j + A[i]] = 1;
                }
            }
        }
    }

    cout << P << endl;
    return 0;
}