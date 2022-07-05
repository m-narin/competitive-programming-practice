/* 
文字列とその得点
文字列の初出の中でもっとも得点が高い提出は何番目か

入力例
5
aaa 9
bbb 10
ccc 10
ddd 10
bbb 11

出力例
2

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<tuple<int, string, int>> submissions;

    for (int i = 1; i <= N; i++){
        string str;
        int score; 
        cin >> str >> score; 

        // 初出なものだけmake_tupleする
        // しかし、N^2 <= 10^10なのでTLEになる

        bool if_original = true;
        for(int j = 0; j < submissions.size(); j++){
            tuple<int, string, int> submission_tuple = submissions[j];
            if(get<1>(submission_tuple) == str){
                if_original = false;
                break;
            }
        }
        if(if_original){
            submissions.push_back(make_tuple(i, str, score));
        }
    }

    int max_score_of_original = 0;
    int max_score_of_index = 1;

    for (int i = 0; i < submissions.size(); i++){
        tuple<int, string, int> submission_tuple = submissions[i];
        if(get<2>(submission_tuple) > max_score_of_original){
            max_score_of_original = get<2>(submission_tuple);
            max_score_of_index = get<0>(submission_tuple);
        }
    }

    cout << max_score_of_index << endl;
}
