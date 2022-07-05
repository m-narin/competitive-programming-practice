/* 
xiが書かれたボールを右隣のものと入れ替える
右端は左隣りのものと

入力例
5 5
1
2
3
4
5

出力例
1 2 3 5 4

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;


    // O(NQ) <= 10^10でTLEになるので、ボールの位置を管理する
    // 最初、1は1番目にあることを表す
    // pos = [0,1,2,3,4,5]
    // balls = [0,1,2,3,4,5]
    vector<int> balls(n+1);
    vector<int> pos(n+1);

    for (int i = 1; i <= n; i++){
        balls[i] = i;
        pos[i] = i;
    }

    // 各命令
    vector<int> x(q);
    for (int i = 0; i < q; i++){
        cin >> x[i];
    }

    for (int i = 0; i < q; i++){
        int p0 = pos[x[i]]; // 1
        int p1 = p0;

        if(p0!=n){
            p1++;
        }else{
            p1--;
        }

        int v0 = balls[p0];
        int v1 = balls[p1];

        // 配列の要素を入れ替える
        swap(balls[p0], balls[p1]); // balls = [0,2,1,3,4,5]
        swap(pos[v0], pos[v1]); // pos = [0,2,1,3,4,5]
    }

    for(int i = 1; i <= n; i++){
        cout << balls[i] << " ";
    }
}