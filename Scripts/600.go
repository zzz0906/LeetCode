func findIntegers(n int) int {
	s := strconv.FormatInt(int64(n), 2) // attention: in golang the default is big endian

	numberOfDigits := len(s)

	dp := make([]int, 32)
	dp[0] = 1
	dp[1] = 2
	for i := 2; i < numberOfDigits; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}

	var res int
	for i := 0; i < numberOfDigits; i++ {
		if s[i] == '0' {
			continue
		}
		res += dp[numberOfDigits-i-1]
		if i > 0 && s[i-1] == '1' { // all the rest substring answer will be meaningless
			return res
		}
	}

	return res + 1
}