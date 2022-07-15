/* 
N頂点、M辺の連結な単純無向グラフ
自分自身より頂点番号が小さい隣接頂点がちょうど1つ存在する
頂点の個数はいくつか？

入力例
5 5
1 2
1 3
3 2
5 2
4 2

出力例
3

*/

#include <bits/stdc++.h>
using namespace std;

// グラフは隣接行列か隣接リストで表現する
// 隣接行列 O(N^2) 
// 隣接リスト O(N+M)
// 今回はN^2 = 10^10になるので、隣接リストで行う
int main() {

    int N, M;
	cin >> N >> M;

    // 2次元配列で隣接リストを表現する 
    // [[2,3][1,3,5,4][1,2][2][2]]
    vector<vector<int> > G(N);

    for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; 
        
        // 0オリジンに修正
        --a, --b;

		G[a].push_back(b);
		G[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        // 自分自身より頂点番号が小さい隣接頂点がちょうど1つ存在する

        int cnt = 0;
        for(int j : G[i]){
            if(j < i){
                cnt++;
            }
        }
        if(cnt == 1){
            ans++;
        }
    }

    cout << ans << endl;
}