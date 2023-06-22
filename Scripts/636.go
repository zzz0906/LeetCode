func exclusiveTime(n int, logs []string) []int {
	stack := make([]int, 0)
	res := make([]int, n)
	prev := 0
	for _, log := range logs {
		s := strings.Split(log, ":")
		id, _ := strconv.Atoi(s[0])
		time, _ := strconv.Atoi(s[2])
		if s[1] == "start" {
			if len(stack) > 0 {
				res[stack[len(stack)-1]] += time - prev
			}
			stack = append(stack, id)
			prev = time
		} else {
			res[stack[len(stack)-1]] += time - prev + 1
			stack = stack[:len(stack)-1]
			prev = time + 1
		}
	}
	return res
}