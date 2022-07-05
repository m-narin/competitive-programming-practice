/* 
K回の操作でAをBに一致させることができるか
操作 : Aiを、Ai+1 or Ai-1に置き換える

入力例
2 5
1 3
2 1

出力例
Yes
*/

#include <bits/stdc++.h>
using namespace std;

// 方針
// 一致できる条件(パリティチェックと範囲)
// ・各配列の差の和とKの偶奇が一致
// ・各配列の差の和 <= K 

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    for (int i = 0; i < n; i++){
        cin >> B[i];
    }

    string ans = "Yes";
    int diff_sum = 0;

    for (int i = 0; i < n; i++){
        diff_sum += abs(A[i] - B[i]);
    }

    // パリティチェック
	if (diff_sum % 2 != k % 2) {
		cout << "No" << endl;
		return 0;
	}

    // A,B配列各要素の差の和 <= k でなければダメ
    if(diff_sum > k){
        ans = "No";
    }

    cout << ans << endl;
}