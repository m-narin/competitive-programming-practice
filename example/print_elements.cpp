/* 
入力を配列で受け取って、配列から各要素を出力する

入力例
3
2 3 4

出力例
2 3 4

*/

#include <bits/stdc++.h>
using namespace std;

int printElements(auto v){
    for (auto item : v) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
};

int main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++){
        cin >> vec[i];
    }

    printElements(vec);
}

