/* 
6個の整数h1, h2, h3, w1, w2, w3がある。
3x3の各マスに以下の条件を満たすように正の整数を1つずつ書く。
各行の和がhi、各列の和がwi。
条件を満たす書き方は何通りか。

入力例
3 4 6 3 3 7

出力例
1

*/


#include <bits/stdc++.h>
using namespace std;

int h1, h2, h3, w1, w2, w3, ans=0;

int main() {

    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    for(int i = 1; i <= 28; i++){
        for (int j = 1; j <= 28; j++){
            for(int k = 1; k <= 28; k++){
                for(int l = 1; l <= 28; l++){
                    if(i+j<h1 && k+l<h2 && i+k<w1 && j+l<w2){
                        int a, b, c, d;
                        a = w1 - i - k;
                        b = w2 - j - l;
                        c = h1 - i - j;
                        d = h2 - k - l;
                        if(a+b<h3 && c+d<w3){
                            if(h3-a-b == w3-c-d){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}