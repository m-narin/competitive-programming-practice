#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
string S[1 << 18];

// mapはキーを順序付けられた平行二分木の構造を持つため、
// 検索時間はO(logN)となる
map<string, int> Map;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];

        // 初出だった場合、Mapの該当文字列キーの値を1にセットして出力
		if (Map[S[i]] == 0) {
			Map[S[i]] = 1;
			cout << i << endl;
		}
	}
	return 0;
}