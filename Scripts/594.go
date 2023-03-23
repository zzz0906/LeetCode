func findLHS(nums []int) int {
	m := make(map[int]int)
	for _, num := range nums {
		m[num]++
	}
	res := 0
	for v := range m {
		if m[v+1] > 0 {
			if m[v]+m[v+1] > res {
				res = m[v] + m[v+1]
			}
		}
	}
	return res
}