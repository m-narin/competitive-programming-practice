/* 
N個のピースに分かれている円形のケーキがある。
連続するピースを選んで、全体の1/10になるものは存在するか？

入力例
10
1 1 1 1 1 1 1 1 1 1

出力例
Yes

*/


#include <iostream>
using namespace std;

long long N, A[1 << 19];
long long B[1 << 19];

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 2周して累積和をとる
	for (int i = 1; i <= N; i++) B[i] = B[i - 1] + A[i];

	for (int i = 1; i <= N; i++) B[i + N] = B[i + N - 1] + A[i];
	if (B[N] % 10LL != 0LL) {
		cout << "No" << endl;
		return 0;
	}

	
	for (int i = 0; i <= N; i++) {
		long long goal = B[i] + B[N] / 10LL;
		int pos1 = lower_bound(B, B + 2 * N + 1, goal) - B;
		if (B[pos1] == goal) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}