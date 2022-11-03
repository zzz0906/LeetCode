func distributeCandies(candyType []int) int {
	var m = make(map[int]int)
	for _, v := range candyType {
		m[v]++
	}
	var n = len(candyType) / 2
	if len(m) < n {
		return len(m)
	}
	return n
}