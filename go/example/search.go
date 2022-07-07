/* 探索
ソートしてから2分探索すれば計算量をO(logn)にできる

出力例
3 -1
4 -1
3 -1
1 -1

*/

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
	"sort"
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

	// 文字列の中に特定の文字列が含まれるか検索
	str := "go-stringsパッケージ-string.Index"
	r := strings.Index(str,"str")
	r2 := strings.Index(str,"wow")
	fmt.Println(r, r2)

	// 数字の中に特定の数字があるか検索
	num := 54321
	numStr := i2s(num)
	fmt.Printf("%T %v \n",numStr,numStr)
	t := strings.Index(numStr,"1")
	t2 := strings.Index(numStr,"8")
	fmt.Println(t, t2)

	// intスライスの中に特定の要素が含まれるか検索
	arrayInt := []int{50,99,50,1,4,5,70}
	sort.Ints(arrayInt)
	p := searchIntTargetInSortedSlice(arrayInt,50)
	p2 := searchIntTargetInSortedSlice(arrayInt,100)
	fmt.Println(p, p2)

	// stringスライスの中に特定の要素が含まれるか検索
	arrayStr := []string{"banana","apple","lemon","orange"}
	sort.Strings(arrayStr)
	q := searchStringTargetInSortedSlice(arrayStr,"banana")
	q2 := searchStringTargetInSortedSlice(arrayStr,"grape")
	fmt.Println(q, q2)
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