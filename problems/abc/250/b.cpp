/* 
タイルを出力

入力例
4 3 2

出力例
..##..##
..##..##
..##..##
##..##..
##..##..
##..##..
..##..##
..##..##
..##..##
##..##..
##..##..
##..##..

*/

#include <bits/stdc++.h>
using namespace std;

// 方針
// 白黒のタイル行列
// 各マス数の剰余系を使って白黒のマスを作成

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<char>> tiles(n, vector<char>(n, '-'));

    for (int i = 0; i < n; i++){
        if(i % 2 == 0){
            for (int j = 0; j < n; j++){
                if(j % 2 == 0){
                    tiles[i][j] = '.';
                }else{
                    tiles[i][j] = '#';
                }
            }
            
        }else{
            for (int j = 0; j < n; j++){
                if(j % 2 == 0){
                    tiles[i][j] = '#';
                }else{
                    tiles[i][j] = '.';
                }
            }
        }
    }

    vector<string> X(a*n,string(b*n,'-'));

    for(int i=0;i < a*n; i++){
        for(int j=0; j < b*n; j++){
            X[i][j] = tiles[i / a][j / b];
        }
    }

    for(int i=0;i < a*n; i++){
        cout << X[i] << endl;
    }

}