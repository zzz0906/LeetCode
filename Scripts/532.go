func min(x int, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}
func max(x int, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}
func findPairs(nums []int, k int) int {
	m := map[int]int{}
	count := map[int]bool{}

	res := 0
	for _, val := range nums {
		_, ok0 := m[val]
		if ok0 {
			m[val] += 1
		} else {
			m[val] = 1
		}

		if k == 0 {
			_, okcount := count[val]
			if m[val] > 1 && !okcount {
				res++
				count[val] = true
			}
		}
	}
	if k == 0 {
		return res
	}
	for _, val := range nums {
		//plus
		_, ok1 := m[min(val, val-k)]
		_, ok2 := m[max(val, val-k)]
		_, ok3 := count[min(val, val-k)]
		if ok1 && ok2 && !ok3 {
			count[min(val, val-k)] = true
			res++
		}
		//minus
		_, ok1 = m[max(val, val+k)]
		_, ok2 = m[min(val, val+k)]
		_, ok3 = count[min(val, val+k)]
		if ok1 && ok2 && !ok3 {
			count[min(val, val+k)] = true
			res++
		}

	}
	return res
}