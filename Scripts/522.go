package main

import (
	"fmt"
	"sort"
)

func findLUSlength(strs []string) int {
	sort.Slice(strs, func(i, j int) bool {
		if len(strs[i]) == len(strs[j]) {
			return strs[i] < strs[j]
		}
		return len(strs[i]) > len(strs[j])
	})
	var i = 0
	for {
		if i == len(strs) {
			break
		}
		if i < len(strs)-1 && strs[i] == strs[i+1] {
			i++
		} else {
			//determine whether a substring of the string before
			var flag = false
			var j = 0
			for j = 0; j < i; j++ {
				var l = 0
				var k = 0
				for k = 0; k < len(strs[j]) && l < len(strs[i]); k++ {
					if strs[j][k] == strs[i][l] {
						l++
					}
				}
				if l == len(strs[i]) {
					flag = true
				}
			}
			if !flag {
				return len(strs[i])
			}
		}
		i++
	}
	return -1
}
func main() {
	var arr = []string{"aaab", "aaa", "bb"}
	fmt.Println(findLUSlength(arr))
}
