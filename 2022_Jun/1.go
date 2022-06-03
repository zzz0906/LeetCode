func runningSum(nums []int) []int {
	var res []int
	sum := 0
	for _, val := range nums {
		sum += val
		res = append(res, sum)
	}
	return res
}