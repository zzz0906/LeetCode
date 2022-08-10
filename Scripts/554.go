func leastBricks(wall [][]int) int {
	var ends_length_map = make(map[int]int)
	var max_ends_count = 0
	for _, row := range wall {
		var cur_ends_count = 0
		for i := 0; i < len(row)-1; i++ {
			cur_ends_count += row[i]
			ends_length_map[cur_ends_count]++
			if ends_length_map[cur_ends_count] > max_ends_count {
				max_ends_count = ends_length_map[cur_ends_count]
			}
		}
	}
	return len(wall) - max_ends_count
}