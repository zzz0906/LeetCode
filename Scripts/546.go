package main

import "fmt"

func removeBoxes(boxes []int) int {
	for i := 0; i < len(boxes); i++ {
		for j:= 0; j < 
	}
}

func main() {
	boxes := []int{1, 3, 2, 2, 2, 3, 4, 3, 1}

	test := [6]int{}
	for i := range test {
		test[i] = i
	}
	fmt.Print(test)
	fmt.Print(removeBoxes(boxes))
}
