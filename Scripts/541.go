func reverseStr(s string, k int) string {
	buf := []rune(s)
	iterationIndex := 0
	for iterationIndex < len(buf) {
		start := iterationIndex
		end := iterationIndex + k - 1
		if end >= len(buf) {
			end = len(buf) - 1
		}
		for start < end {
			buf[start], buf[end] = buf[end], buf[start]
			start++
			end--
		}
		iterationIndex += 2 * k
	}
	return string(buf)
}