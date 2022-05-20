type Solution struct {
	w []int
    prefix int
}

func Constructor(w []int) Solution {
	var s Solution
    s.w = w;
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
	var l = 0
	var r = len(this.w) - 1
	for l < r {
		var m = (l + r) / 2
		if this.w[m] < random {
			l = m + 1
		} else {
			r = m
		}
	}
	return l
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(w);
 * param_1 := obj.PickIndex();
 */