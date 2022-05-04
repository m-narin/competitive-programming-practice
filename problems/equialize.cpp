/*
数列となり同士を以下の操作にする
1. 小さい数字を大きい数字に合わせる
2. 大きい数字を小さい数字に合わせる


入力例
5
2 4 6 6 6

出力例
2
1 2 3 
1 1 2 

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0 ; i < n ; i++)
        cin >> A.at(i);

    // 最頻値を求める
    int mode = 0;
    int mode_num = 0;
    for (int i = 0; i < A.size(); i++){
        int count = 1;
        for (int j = 0; j < A.size(); j++){
            if (i != j){
                if(A.at(i) == A.at(j)){
                    count++;
                }
            }
        }

        if(count > mode){
            mode = count;
            mode_num = A.at(i);
        }
    }

    // 操作の実施回数
    int ope_num = A.size() - mode;
    
    cout << ope_num << endl;

    // 最頻値のindex
    vector<int> mode_index(mode);

    for(int i = 0; i < A.size(); i++){
        if(A.at(i) == mode_num){
            mode_index.push_back(i);
        }
    }

}