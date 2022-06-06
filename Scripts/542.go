func min(x int, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}
func updateMatrix(mat [][]int) [][]int {
	res := [][]int{}
	for _, element := range mat {
		tmp := []int{}
		for _, v := range element {
			if v == 0 {
				tmp = append(tmp, v)
			} else {
				tmp = append(tmp, math.MaxInt-1)
			}
		}
		res = append(res, tmp)
	}

	for i := 0; i < len(mat); i++ {
		for j := 0; j < len(mat[i]); j++ {
			if mat[i][j] != 0 {
				if i > 0 {
					res[i][j] = min(res[i][j], res[i-1][j]+1)
				}
				if j > 0 {
					res[i][j] = min(res[i][j], res[i][j-1]+1)
				}
			}
		}
	}

	for i := len(mat) - 1; i >= 0; i-- {
		for j := len(mat[i]) - 1; j >= 0; j-- {
			if mat[i][j] != 0 {
				if i < len(mat)-1 {
					res[i][j] = min(res[i][j], res[i+1][j]+1)
				}
				if j < len(mat[i])-1 {
					res[i][j] = min(res[i][j], res[i][j+1]+1)
				}
			}
		}
	}

	return res
}