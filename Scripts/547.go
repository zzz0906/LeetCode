package main

import "fmt"

func dfs(x int, count int, flag []int, isConnected [][]int) {
	flag[x] = count
	for i := 0; i < len(isConnected); i++ {
		if isConnected[x][i] == 1 && flag[i] == 0 {
			dfs(i, count, flag, isConnected)
		}
	}
}
func findCircleNum(isConnected [][]int) int {
	// create 2D slices
	flag := make([]int, len(isConnected))
	n := len(isConnected)
	for i := 0; i < n; i++ {
		flag[i] = 0
	}
	// dfs
	count := 1
	for i := 0; i < n; i++ {
		if flag[i] == 0 {
			dfs(i, count, flag, isConnected)
			count++
		}
	}
	return count - 1
}
func main() {
	fmt.Println(findCircleNum([][]int{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}))
}
