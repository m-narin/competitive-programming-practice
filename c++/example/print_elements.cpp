/* 
配列から各要素を出力する

入力例
なし

出力例
1 2 3 4 5 6 7 8 9 

1 2 3 4 5 6 7 8 9 
2 4 6 8 10 12 14 16 18 
3 6 9 12 15 18 21 24 27 
4 8 12 16 20 24 28 32 36 
5 10 15 20 25 30 35 40 45 
6 12 18 24 30 36 42 48 54 
7 14 21 28 35 42 49 56 63 
8 16 24 32 40 48 56 64 72 
9 18 27 36 45 54 63 72 81 

*/

#include <bits/stdc++.h>
using namespace std;

int printElements(auto v){
    for (auto item : v) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
};

int printDimentionalElements(auto v, int H, int W){
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
};

int main() {
    int N = 9;
    int H = 9;
    int W = 9;

    vector<int> A(N);
    for (int i = 0; i < N; i++){
        A[i] = i+1;
    }

    vector<vector<int>> B(H, vector<int>(W));

    for (int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            B[i][j] = (i+1)*(j+1);
        }
    }

    printElements(A);
    cout << endl;
    printDimentionalElements(B,H,W);
}

