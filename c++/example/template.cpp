/* 

入力例

出力例

*/


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = numeric_limits<ll>::max();

int printElements(auto v){
    for (auto item : v) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
};

int main() {

    int n;
    cin >> n;
    vector<ll> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;

    cout << ans << '\n';

    return 0;
}