package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
)

func nextGreaterElement(n int) int {
	s := strconv.Itoa(n)
	r := []rune(s)
	l := len(s)

	for i := l - 1; i > 0; i-- {
		if r[i] > r[i-1] {
			for j := l - 1; j >= i; j-- {
				if r[j] > r[i-1] {
					r[i-1], r[j] = r[j], r[i-1]
					tmp := r[i:]
					sort.Slice(tmp, func(a, b int) bool {
						return tmp[a] < tmp[b]
					})

					res, _ := strconv.ParseInt(string(r[:i])+string(tmp), 10, 64)

					if res > math.MaxInt32 {
						return -1
					}
					return int(res)
				}
			}

		}
	}
	return -1
}
func main() {
	fmt.Println(nextGreaterElement(230241))
	// r := []rune("12")
	// fmt.Println(string(r[:1]) + string(r[1:]))
}
