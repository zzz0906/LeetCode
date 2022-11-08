func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func findUnsortedSubarray(nums []int) int {
	start := -1
	end := -2
	mx := nums[0]
	mi := nums[len(nums)-1]
	for i := 1; i < len(nums); i++ {
		mx = max(mx, nums[i])
		mi = min(mi, nums[len(nums)-1-i])
		if nums[i] < mx {
			end = i
		}
		if nums[len(nums)-1-i] > mi {
			start = len(nums) - 1 - i
		}
	}
	return end - start + 1
}