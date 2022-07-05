/* 
選んだ文字列の中でちょうど
K個の文字列の登場する英小文字の種類数の最大値

入力例
4 2
abi
aef
bc
acg

出力例
3

*/

#include <bits/stdc++.h>
using namespace std;

// 組み合わせの全列挙
// bit全探索
int main() {
    int n,k;
    cin >> n >> k;
    int ans = 0;

    vector<string> s(n);
    for(int i = 0; i < s.size(); i++){
        cin >> s[i];
    }

    // bit全探索
    // 1 << nは1をn bit左シフト = 2^n
    for (int i = 0; i < (1 << n); i++){
        vector<int> sum(26);

        for (int j = 0; j < n; j++){

            // ある文字列を選ぶ場合
            // 選ばれるものはiをjだけ右シフトして0か1かを判定する
            // →つまり、iのj桁目が0か1か
            // 1だった場合選ばれる
            if((i>>j) & 1){
                for(int x=0;x<s[j].size();x++){
                    // 各アルファベットに対応した場所を++
                    sum[s[j][x] - 'a']++;
                }
            }
        }

        // ちょうどk個の文字列に含まれるアルファベットをカウント
        int now = 0;
        for(int j=0;j<26;j++){
            if(sum[j] == k){
                now++;
            }
        }

        ans = max(ans, now);
    }
    cout<<ans<<endl;
}