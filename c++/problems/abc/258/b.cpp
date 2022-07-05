/* 
N行N列のマス目があり、上下左右繋がっているものとする。
あるマスから、上下左右斜めの8方向へ、N-1回移動するとき、
通った順番に左から並べた整数としてあり得るものの最大値を求めよ。

入力例
4
1161
1119
7111
1811

出力例
9786

*/


#include <bits/stdc++.h>
using namespace std;

int N;

int main() {

    cin >> N;

    vector<vector<char>> C(N, vector<char>(N)); 

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> C[i][j];
        }
    }

    vector<vector<char>> A(N, vector<char>(N)); 

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            A[i][j] = C[i][j] - '0';
        }
    }


    long long max_num = 0;
    
    // 各マス始点
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            long long num_right = 0;
            long long num_left = 0;
            long long num_top = 0;
            long long num_bottom = 0;
            long long num_right_top = 0;
            long long num_right_bottom = 0;
            long long num_left_top = 0;
            long long num_left_bottom = 0;

            for(int k = 0; k <= N-1; k++){
                long long keta = 1LL;
                for(int l = 1; l <= N-1-k; l++){
                    keta *= 10LL;
                }

                num_right += A[i][(j+k) % N] * keta;
                num_left += A[i][(j-k+N) % N] * keta;
                num_top += A[(i+k) % N][j] * keta;
                num_bottom += A[(i-k+N) % N][j] * keta;
                num_right_top += A[(i+k) % N][(j+k) % N] * keta;
                num_right_bottom += A[(i-k+N) % N][(j+k) % N] * keta;
                num_left_top += A[(i+k) % N][(j-k+N) % N] * keta;
                num_left_bottom += A[(i-k+N) % N][(j-k+N) % N] * keta;
            }

            vector<long long> B = {num_right,num_left,num_top,num_bottom,num_right_top,num_right_bottom,num_left_top,num_left_bottom};

            for(int i = 0; i < 8; i++){
                if (max_num < B[i]){
                    max_num = B[i];
                }
            }
        }
    }

    cout << max_num << endl;

    return 0;
}