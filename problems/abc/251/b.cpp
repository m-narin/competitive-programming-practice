/* 
3個以下の重りを自由に選んだときの和のパターン数
和は指定の数以下で

入力例
2 10
1 3

出力例
3

*/

#include <bits/stdc++.h>
using namespace std;

// N = 300なので、全探索OK
int main() {
    int n, w;
    cin >> n >> w;

    vector<int> num_list(n);
    for (int i = 0; i < n; i++){
        cin >> num_list.at(i);
    }

    set<int> values;

    // 1個選ぶ場合

    // 文字配列を出力
    for(int i : num_list){
        if(i <= w ){
            values.insert(i);
        }
    }

    // 2個選ぶ場合
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < j && num_list[i]+num_list[j] <= w ){
                values.insert(num_list[i]+num_list[j]);
            }
        }
    }


    // 3個選ぶ場合
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i < j && j < k && num_list[i] + num_list[j] + num_list[k] <= w ){
                    values.insert(num_list[i]+num_list[j]+num_list[k]);
                }
            }
        }
    }

    cout << values.size() << endl;
}