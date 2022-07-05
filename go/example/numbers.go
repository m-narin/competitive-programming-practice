/*計算量や数値のサイズについて

１．制限時間は2秒。1秒あたり最大10^8回程度の計算が可能

・Nが10^6 → O(N)かO(N log N)
・Nが10^5 → O(N log N)かO(N log2 N)
・Nが3000 → O(N^2)
・Nが300 → O(N^3)(シンプルな処理)
・Nが100 → O(N^3)
・Nが50 → O(N^4)
・Nが20 → O(2^N)かO(N*2^N)

AtcoderにおけるGoのint型(64bit)は、2^63 ≒ 10^18を超えるとオーバーフローになる

出力例
7
1024
2
3
300000007
300000007
0 2
2 7
769682799
9223372036854775807

*/

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
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

	// abs
	// 7
	fmt.Println(abs(-7))

	// pow
	// 1024
	fmt.Println(pow(2,10))

	// mod
	// 負の余りも大丈夫
	// 2
	// 3
	fmt.Println(mod(22,5))
	fmt.Println(mod(-2,5))

	// modPow 累乗したものをMOD(=1000000007)で割る
	// 300000007
	// 300000007
	fmt.Println(modPow(10,17))
	fmt.Println(pow(10,17) % MOD)

	// 最大値、最小値
	// 0 2
	// 2 7
	slice := []int{2,3,7}
	minIdx, minNum := min(slice...)
	maxIdx, maxNum := max(2,3,7)
	fmt.Println(minIdx, minNum)
	fmt.Println(maxIdx, maxNum)

	// オーバーフローに注意 
	// 769682799
	a := 111111111
	b := 123456789
	c := 987654321
	fmt.Println(a * b % MOD * c % MOD)

	// 64bitの最大値を出力
	fmt.Println(INF)
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
	lines := strings.Split(readLine(), "")
	for _, v := range lines {
		if v == " "{
			continue
		}
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

func min(values ...int) (int,int) {
	ret := values[0]
	idx := 0
	for i, v := range values {
		if ret > v {
			idx = i
			ret = v
		}
	}
	return idx, ret
}

func max(values ...int) (int,int) {
	ret := values[0]
	idx := 0
	for i, v := range values {
		if ret < v {
			idx = i
			ret = v
		}
	}
	return idx, ret
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