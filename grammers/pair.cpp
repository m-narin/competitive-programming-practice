/* 
2番目が小さい順に並べ替え

入力例
3
5 2
2 7
4 1

出力例
4 1
5 2
2 7

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> pairs(N);

    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b; 

        // b, aの順でペア
        pairs.at(i) = make_pair(b, a);
    }

    sort(pairs.begin(), pairs.end());

    // 配列の各要素=pair
    for (auto p : pairs){

        // もとの順に表示
        cout << p.second << " " << p.first << endl;
    }
}

