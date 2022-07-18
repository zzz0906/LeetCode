func checkRecord(s string) bool {
	absentCount := 0
	lateCount := 0
	for _, chr := range s {
		if chr == 'A' {
			absentCount++
		}
		if absentCount >= 2 {
			return false
		}

		if chr == 'L' {
			lateCount++
		} else {
			lateCount = 0
		}
		if lateCount > 2 {
			return false
		}
	}
	return true
}