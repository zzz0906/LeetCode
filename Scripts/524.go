func findLongestWord(s string, dictionary []string) string {
	res := ""
	for _, c := range dictionary {
		index := 0
		match := false
		for i := 0; i < len(s); i++ {
			if c[index] == s[i] {
				index++
				if index == len(c) {
					match = true
					break
				}
			}
		}
		if match && (len(c) > len(res) || (len(c) == len(res) && c < res)) {
			res = c
		}
	}
	return res
}