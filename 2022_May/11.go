func countVowelStrings(n int) int {

	count := [6]int{0, 1, 1, 1, 1, 1}
	for i := 1; i < n; i++ {
		for i := 2; i < 6; i++ {
			count[i] += count[i-1]
		}
	}

	return count[5] + count[4] + count[3] + count[2] + count[1]
}