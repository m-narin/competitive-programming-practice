/*標準入出力まとめ

入力例
hello
1
1 2 3
1 2 3
3
1
12
123
3
111
111
111

出力例
hello
1
1 2 3
[1 2 3]
[1 12 123]
[[1 1 1] [1 1 1] [1 1 1]]

*/

// Template: https://github.com/maitaken/atcoder-template
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

	// 横並び連続の文字列を読み込む
	// <- hello
	// -> hello
	var a string = readLine()
	fmt.Println(a)

	// 数字1つ読み込む
	// <- 1
	// -> 1
	var b int = readInt()
	fmt.Println(b)

	// 横並び空白区切りの数字を各変数に読み込む
	// <- 1 2 3
	// -> 1 2 3
	var c,d,e int = readInt3()
	fmt.Println(c,d,e)

	// 横並び連続の数字をスライスで読み込む
	// ""で区切りを変える
	// <- 1 2 3 or 123
	// -> 1 2 3
	var f []int = readIntSlice()
	fmt.Println(f)

	// 複数行の数値をスライスで読み込む
	// <- 3
	// <- 1
	// <- 12
	// <- 123
	var g int = readInt()
	h := make([]int, g)
	for i := 0; i < g; i++{
		h[i] = readInt()
	}
	fmt.Println(h) 

	// 2次元スライスを読み込む
	// <- 3
	// <- 111
	// <- 111
	// <- 111
	// ->[[1 1 1] [1 1 1] [1 1 1]]
	var q int = readInt()
	r := make([][]int, q)
	for i := 0; i < q; i++{
		r[i] = readIntSlice() 
	}
	fmt.Println(r) 

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