func outerTrees(trees [][]int) [][]int {
	isMoreClockWise := func(a, b, c []int) int {
		return (c[0]-a[0])*(b[1]-a[1]) - (c[1]-a[1])*(b[0]-a[0])
	}

	n := len(trees)
	if n < 4 {
		return trees
	}

	// Find most left tree
	minLeft := 0
	for i, val := range trees {
		if val[0] < trees[minLeft][0] {
			minLeft = i
		}
	}

	res := make(map[int][]int, 0)

	cur := minLeft
	for j := 0; j < n; j++ {
		cand := (cur + 1) % n
		for i := 0; i < n; i++ {
			if isMoreClockWise(trees[cur], trees[cand], trees[i]) > 0 {
				cand = i
			}
		}
		for i := 0; i < n; i++ {
			if isMoreClockWise(trees[cur], trees[cand], trees[i]) == 0 {
				res[i] = trees[i]
			}
		}
		cur = cand
		if cur == minLeft {
			break
		}
	}

	result := make([][]int, 0)
	for _, val := range res {
		result = append(result, val)
	}
	return result
}