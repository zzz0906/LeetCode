func triangleNumber(nums []int) int {
	sort.Ints(nums)
	res := 0
	for i := len(nums) - 1; i >= 2; i-- {
		l, r := 0, i-1
		for l < r {
			if nums[l]+nums[r] > nums[i] {
				res += r - l
				r--
			} else {
				l++
			}
		}
	}
	return res
}