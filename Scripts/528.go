type Solution struct {
	w      []int
	prefix int
}

func LowerBound(array []int, target int) int {
	low, high, mid := 0, len(array)-1, 0
	for low <= high {
		mid = (low + high) / 2
		if array[mid] >= target {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return low
}

func Constructor(w []int) Solution {
	var s Solution
	s.w = w
	var prefix int
	prefix = 0
	for ind, val := range w {
		prefix += val
		s.w[ind] = prefix
	}
	s.prefix = prefix
	return s
}

func (this *Solution) PickIndex() int {
	var random = rand.Intn(this.prefix)
	return LowerBound(this.w, random)
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(w);
 * param_1 := obj.PickIndex();
 */