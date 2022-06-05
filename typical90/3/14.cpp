/* 
N人の小学生と、N校の学校
全生徒が別々の学校に通い、家と学校の距離の総和の最小値を出力

入力例
6
8 6 9 1 2 0
1 5 7 2 3 9

出力例
5

*/

#include <bits/stdc++.h>
using namespace std;

// ソートして貪欲法

const int INF = 2000000000;

int main() {

    int N;
	cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<int> B(N);
    for (int i = 0; i < N; i++){
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long dis = 0;

    for (int i = 0; i < N; i++){
        dis += abs(A[i] - B[i]);
    }

    cout << dis << endl;
}