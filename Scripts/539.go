func findMinDifference(timePoints []string) int {
	var simplyTimePoints []int

	for index := range timePoints {
		h, _ := strconv.Atoi(strings.Split(timePoints[index], ":")[0])
		m, _ := strconv.Atoi(strings.Split(timePoints[index], ":")[1])
		simplyTimePoints = append(simplyTimePoints, h*60+m)
	}
	sort.Ints(simplyTimePoints)

	minDifference := simplyTimePoints[len(simplyTimePoints)-1] - simplyTimePoints[0]

	if 24*60-simplyTimePoints[len(simplyTimePoints)-1]+simplyTimePoints[0] < minDifference {
		minDifference = 24*60 - simplyTimePoints[len(simplyTimePoints)-1] + simplyTimePoints[0]
	}
	for index := range simplyTimePoints {
		if index != len(simplyTimePoints)-1 {
			if simplyTimePoints[index+1]-simplyTimePoints[index] < minDifference {
				minDifference = simplyTimePoints[index+1] - simplyTimePoints[index]
			}
		}
	}
	return minDifference
}