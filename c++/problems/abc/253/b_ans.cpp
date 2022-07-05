/* 
H x Wのうち、2つのマスに駒が置かれている
片方移動して最小何回でもう片方の場所に到達できるか？

入力例
2 3
--o
o--

出力例
3

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<pair<int, int>> p;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            char c;
            cin >> c;
            if(c == 'o'){
                p.push_back(make_pair(i, j));
            }
        }
    }

    int dis = abs(p[0].first - p[1].first) + abs(p[0].second - p[1].second);

    cout << dis << endl;
}