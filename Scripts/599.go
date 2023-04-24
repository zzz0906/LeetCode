func findRestaurant(list1 []string, list2 []string) []string {
	value2index := make(map[string]int)
	for i, v := range list2 {
		value2index[v] = i
	}
	min := len(list1) + len(list2) + 1
	var result []string
	for i, v := range list1 {
		if j, ok := value2index[v]; ok {
			if i+j < min {
				min = i + j
				result = []string{v}
			} else if i+j == min {
				result = append(result, v)
			}
		}
	}
	return result
}