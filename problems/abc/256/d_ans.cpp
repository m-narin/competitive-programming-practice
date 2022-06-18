/* 
L以上R未満からなる実数の集合を[L,R)とする。
N個の右半開区間が与えられる。
それらの和集合を最小の右半開区間の和集合で表せ。
[X,Y)のXの昇順で記述する。

入力例
3
10 20
20 30
40 50

出力例
10 30
40 50

*/


#include <bits/stdc++.h>
using namespace std;

// ログインログアウトの時刻と考え、
// ユーザー数が1以上の時刻の区間を求める
// ログイン人数が0から1以上、1以上から0になった時刻が求まれば良い

int main(){
	int n;
	cin >> n;
	vector<pair<int,int>>query;
	for(int i=0;i<n;i++){
		int l,r;
		cin >> l >> r;

        // ログイン
		query.push_back({l,0});

        // ログアウト
		query.push_back({r,1});
	}

    // ログインログアウト合わせて昇順ソート
	sort(query.begin(),query.end());
	
    // ログイン人数
	int cnt=0;
	for(auto[t,f]:query){

        // ログインした場合
		if(f==0){

            // ログイン人数が1以上になったとき
			if(cnt==0)cout << t << ' ';
			cnt++;
        
        // ログアウトした場合
		}else{

            // 人数減る
			cnt--;

            // ログイン人数が0になったら
			if(cnt==0)cout << t << endl;
		}
	}
}