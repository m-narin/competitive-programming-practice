/*
偶奇が異なる要素を交互に削除し、
残った要素の総和を最小化したい
最小値を出力


入力例
5
1 5 7 8 2

出力例
0

入力例
2
1000000 1000000

出力例
1000000

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec.at(i);
    
    int sum = 0;
    for(int i = 0; i < N; i++) sum += vec.at(i);
    
    vector<int> odd(0);
    vector<int> even(0);
    for(int i = 0; i < N; i++){
        if(vec.at(i) % 2 == 1) odd.push_back(vec.at(i));
        else even.push_back(vec.at(i));
    }

    sort(odd.begin(), odd.end());
    reverse(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    reverse(even.begin(), even.end());
    
    int k = min(odd.size(), even.size());
    
    // 要素数が大きい方の大きい数字から引いていく
    for(int i = 0; i < k; i++){
        sum -= odd.at(i);
        sum -= even.at(i);
    }
    
    if(odd.size() != even.size()){
        if(k == odd.size()){
            sum -= even.at(k);
        }else{
            sum -= odd.at(k);
        }
    }
    
    cout << sum;
}