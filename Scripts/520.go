package main

import "fmt"

func detectCapitalUse(word string) bool {
	//edge cases
	if len(word) == 0 {
		return true
	}

	// 1. all captial
	f := true
	for i := 0; i < len(word); i = i + 1 {
		if int(word[i]) < 65 || int(word[i]) > 90 {
			f = false
		}
	}
	if f {
		return true
	}

	//2. all not capital
	f = true
	for i := 0; i < len(word); i = i + 1 {
		if int(word[i]) < 97 || int(word[i]) > 122 {
			f = false
		}
	}
	if f {
		return true
	}

	//3. first capital following all not capital
	if word[0] >= 65 && word[0] <= 90 {
		f = true
		for i := 1; i < len(word); i = i + 1 {
			if int(word[i]) < 97 || int(word[i]) > 122 {
				f = false
			}
		}
		if f {
			return true
		}
	}

	return false
}

func main() {
	fmt.Println("Hello, World!")
}
