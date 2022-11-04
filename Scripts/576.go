type ballStatus struct {
	movesLeft int
	row       int
	col       int
}

func findPaths(m int, n int, moves int, row int, col int) int {
	memo := make(map[ballStatus]int, m*n*moves)
	return findPathsWithMemo(memo, m, n, moves, row, col)
}

func findPathsWithMemo(memo map[ballStatus]int, m, n, moves, row, col int) int {
	if row < 0 || row >= m || col < 0 || col >= n {
		return 1
	}
	if moves == 0 {
		return 0
	}
	input := ballStatus{moves, row, col}
	if paths, isMemoized := memo[input]; isMemoized {
		return paths
	}
	const mod = int(1e9 + 7)
	paths := 0 +
		findPathsWithMemo(memo, m, n, moves-1, row-1, col)%mod +
		findPathsWithMemo(memo, m, n, moves-1, row+1, col)%mod +
		findPathsWithMemo(memo, m, n, moves-1, row, col-1)%mod +
		findPathsWithMemo(memo, m, n, moves-1, row, col+1)%mod
	memo[input] = paths % mod
	return memo[input]
}