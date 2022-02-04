package main

func findLUSlength(a string, b string) int {
	if len(a) > len(b) {
		return len(a)
	}
	if len(b) > len(a) {
		return len(b)
	}
	if a == b {
		return -1
	}
	return len(a)
}
