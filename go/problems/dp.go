/*
n個の品物があり、i番目の品物のそれぞれの重さと価値が与えられる。
総和がwを越えないように選んだ時の、価値の総和の最大値を求めよ。

入力例
6 9
2 3
1 2
3 6
2 1
1 3
5 85 

出力例
94

*/

// DP問題
// 問題を部分問題の総和として考える
// dp[i]が決まっているときに、dp[i+1]を考える
// つまり、a[i]を選ぶか選ばないか
// 参考
// https://qiita.com/drken/items/a5e6fe22863b7992efdb
// https://o-treetree.hatenablog.com/entry/DPL1B

/* 
あああ

入力例

出力例

*/

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	// "sort"
)

const (
	BUFSIZE = 10000000
	MOD     = 1000000007
	INF     = 1<<63 - 1 // 9223372036854775807 ≒ 9e18
)

var rdr *bufio.Reader

func main() {
	rdr = bufio.NewReaderSize(os.Stdin, BUFSIZE)
	solve()
}

func solve() {
	n,W := readInt2()
    value := make([]int, n)
    weight := make([]int, n)

    // dpテーブル
    // dp[i+1][w] := i番目までの品物の中から重さがwを越えないように選んだ時の、価値の総和の最大値
    var dp[110][1100]int

	for i := 0; i < n; i++{
        a,b := readInt2()
        weight[i] = a
		value[i] = b
	}
    
    // DP初期条件: dp[0][w] = 0
    for w := 0; w <= W; w++{
        dp[0][w] = 0
    }

    //DP ループ
    for i := 0; i < n; i++{
        for w := 0; w <= W; w++{
            if w >= weight[i]{
                dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w])
            }else{
                dp[i+1][w] = dp[i][w]
            }
        }
    }

    fmt.Println(dp[n][W])
}

// 1行をstringで読み込み
func readLine() string {
	buf := make([]byte, 0, 16)
	for {
		l, p, e := rdr.ReadLine()
		if e != nil {
			fmt.Println(e.Error())
			panic(e)
		}
		buf = append(buf, l...)
		if !p {
			break
		}
	}
	return string(buf)
}

// 1行の数字列を[]int=スライスで読み込み
func readIntSlice() []int {
	slice := make([]int, 0)
	lines := strings.Split(readLine(), " ")
	for _, v := range lines {
		slice = append(slice, s2i(v))
	}
	return slice
}

// 以下a,b := readint2()のように書ける
func readInt() int {
	return s2i(readLine())
}

func readInt2() (int, int) {
	lines := strings.Split(readLine(), " ")
	return s2i(lines[0]), s2i(lines[1])
}

func readInt3() (int, int, int) {
	lines := strings.Split(readLine(), " ")
	return s2i(lines[0]), s2i(lines[1]), s2i(lines[2])
}

func readInt4() (int, int, int, int) {
	lines := strings.Split(readLine(), " ")
	return s2i(lines[0]), s2i(lines[1]), s2i(lines[2]), s2i(lines[3])
}

// For int
func b2i(b bool) int {
	if b {
		return 1
	}
	return 0
}

func i2b(i int) bool {
    return i != 0
}

func abs(v int) int {
	if v < 0 {
		return -v
	}
	return v
}

func pow(x, y int) int {
	return int(math.Pow(float64(x), float64(y)))
}

func mod(x, y int) int {
	m := x % y
	if m < 0 {
		return m + y
	}
	return m
}

func modPow(x, y int) int {
	ret := 1
	for ; y != 0; y >>= 1 {
		if y&1 == 1 {
			ret = mod((ret * x), MOD)
		}
		x = mod(x*x, MOD)
	}
	return ret
}

func min(values ...int) int {
	ret := values[0]
	for _, v := range values {
		if ret > v {
			ret = v
		}
	}
	return ret
}

func max(values ...int) int {
	ret := values[0]
	for _, v := range values {
		if ret < v {
			ret = v
		}
	}
	return ret
}

func s2i(s string) int {
	v, ok := strconv.Atoi(s)
	if ok != nil {
		panic("Faild : " + s + " can't convert to int")
	}
	return v
}

func i2s(i int) string {
	return strconv.Itoa(i)
}

func reverseIntSlice(slice []int) []int {
	new_slice := make([]int,len(slice))
	for i := len(slice) - 1; i >= 0; i--{
		new_slice[len(slice)-1-i] = slice[i]
	}
	return new_slice
}

func reverseStringSlice(slice []string) []string {
	new_slice := make([]string,len(slice))
	for i := len(slice) - 1; i >= 0; i--{
		new_slice[len(slice)-1-i] = slice[i]
	}
	return new_slice
}

func reverseString(s string) string {
	new_s := ""
	for i := len(s) - 1; i >= 0; i--{
		new_s += string(s[i])
	}
	return new_s
}

func uniqueIntSlice(target []int) (unique[]int){

	m := map[int]bool{}

	for _,v := range target{
		if !m[v]{
			m[v] = true
			unique = append(unique, v)
		}
	}

	return unique
}

func uniqueStringSlice(target []string) (unique[]string){

	m := map[string]bool{}

	for _,v := range target{
		if !m[v]{
			m[v] = true
			unique = append(unique, v)
		}
	}

	return unique
}

// ソートされたスライスから2分探索する ~O(log(n))
// targetがあるとき: 最初のindexを返す
// targetがないとき: -1を返す
func searchIntTargetInSortedSlice(array []int, target int) int {

    // 範囲start < endを探索する
    arrayLen := len(array)
    start := 0
    end := arrayLen - 1
    var index int
    for {
        if end < start {
            return -1
        }
        index = (start + end) / 2

        if array[index] == target {
            return index
        }

        if array[index] < target {
            start = index + 1
        } else {
            end = index - 1
        }
    }
}

// ソートされたスライスから2分探索する ~O(log(n))
// targetがあるとき: 最初のindexを返す
// targetがないとき: -1を返す
func searchStringTargetInSortedSlice(array []string, target string) int {

    // 範囲start < endを探索する
    arrayLen := len(array)
    start := 0
    end := arrayLen - 1
    var index int
    for {
        if end < start {
            return -1
        }
        index = (start + end) / 2

        if array[index] == target {
            return index
        }

        if array[index] < target {
            start = index + 1
        } else {
            end = index - 1
        }
    }
}

// 最大公約数
func gcd(v1,v2 int) int {
	if v1 > v2{
		v1, v2 = v2, v1
	}

	for v1 != 0 {
		v1, v2 = v2%v1, v1
	}

	return v2
}

// 最小公倍数
func lcm(v1, v2 int) int{
	return v1*v2 / gcd(v1,v2)
}

// 素因数分解
func primeFactors(n int) []int{
	rem := n
	p := []int{}

	for i:=2; i*i<=n; i++{
		for rem % i == 0{
			rem /= i
			p = append(p,i)
		}
	}

	if rem != 1{
		p = append(p,rem)
	}

	return p
}

// 位数と各位のスライスを返す
func baseNumbers(n int)(int, []int){

	cnt := 0

	slice := []int{}

	for n > 0{
		slice = append(slice, n % 10)
		n /= 10
		cnt++
	}

	slice = reverseIntSlice(slice)

	return cnt, slice
}

// 10進数から2進数に変換してスライスを返す
func base10ToBase2(n int) []int{

	slice := []int{}

	if n == 0{
		return []int{0}
	}

	for n > 0{
		slice = append(slice,n%2)
		n /= 2
	}

	slice = reverseIntSlice(slice)

	return slice
}