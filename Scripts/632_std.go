type PriorityQueue [][2]int

func (pq PriorityQueue) Len() int           { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i][1] < pq[j][1] }
func (pq PriorityQueue) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.([2]int))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[:n-1]
	return item
}

func (pq PriorityQueue) Top() interface{} {
	return pq[0]
}

func smallestRange(nums [][]int) []int {
	// Let's push all numbers along with the index of the list into a priority queue
	var pq PriorityQueue
	for idx, list := range nums {
		for _, num := range list {
			heap.Push(&pq, [2]int{idx, num})
		}
	}
	// window is the sliding window that contains elements popped from the Priority queue
	window := list.New()
	// listsCovered contains the number of elements the window contains from each list
	listsCovered := make([]int, len(nums))
	// windowFound is a boolean that tells us whether we have found a window
	// Once a window is found, we will not shrink the window unless we've expanded the window
	// to accomodate shrinking
	windowFound := false
	var res []int
	minLength := math.MaxInt32

	for pq.Len() > 0 {
		top := heap.Pop(&pq).([2]int)
		listsCovered[top[0]]++
		window.PushBack(top)
		if !windowFound {
			windowFound = found(listsCovered)
		}
		if windowFound {
			// Let's trim left as much as possible by removing duplicate elements from the front
			for window.Len() > len(nums) {
				front := window.Front()
				if listIdx := front.Value.([2]int)[0]; listsCovered[listIdx] > 1 {
					listsCovered[listIdx]--
					window.Remove(front)
				} else {
					break
				}
			}
			first := window.Front().Value.([2]int)[1]
			last := window.Back().Value.([2]int)[1]
			currLength := last - first + 1
			if currLength < minLength {
				minLength = currLength
				res = []int{first, last}
			}
		}
	}
	return res
}

func found(listsCovered []int) bool {
	for i := 0; i < len(listsCovered); i++ {
		if listsCovered[i] == 0 {
			return false
		}
	}
	return true
}