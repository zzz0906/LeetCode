func dfs(x int, y int, board *[][]byte) {
	dirs := [][]int{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}
	if (*board)[x][y] == 'M' || (*board)[x][y] == 'X' {
		return
	}
	var count = 0
	for dir := range dirs {
		nx, ny := x+dirs[dir][0], y+dirs[dir][1]
		if nx < 0 || nx >= len(*board) || ny < 0 || ny >= len((*board)[0]) {
			continue
		}
		if (*board)[nx][ny] == 'M' || (*board)[nx][ny] == 'X' {
			count++
		}
	}
	if count == 0 {
		(*board)[x][y] = 'B'
		for dir := range dirs {
			nx, ny := x+dirs[dir][0], y+dirs[dir][1]
			if nx < 0 || nx >= len(*board) || ny < 0 || ny >= len((*board)[0]) || (*board)[nx][ny] != 'E' {
				continue
			}
			dfs(nx, ny, board)
		}
	} else {
		(*board)[x][y] = byte(count + '0')
	}
}
func updateBoard(board [][]byte, click []int) [][]byte {
	if board[click[0]][click[1]] == 'M' {
		board[click[0]][click[1]] = 'X'
		return board
	}
	dfs(click[0], click[1], &board)
	return board
}