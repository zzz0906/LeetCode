type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type MinHeap struct {
	IntHeap
}

func (h MinHeap) Less(i, j int) bool { return h.IntHeap[i] < h.IntHeap[j] }

func smallestRange(nums [][]int) []int {
	h := &MinHeap{}
	heap.Init(h)
	max := 0
	for i := 0; i < len(nums); i++ {
		heap.Push(h, i)
		if nums[i][0] > max {
			max = nums[i][0]
		}
	}
	min := (*h).IntHeap[0]
	res := []int{min, max}
	for {
		minIndex := heap.Pop(h).(int)
		if len(nums[minIndex]) == 1 {
			break
		}
		nums[minIndex] = nums[minIndex][1:]
		heap.Push(h, minIndex)
		max = (*h).IntHeap[0]
		min = (*h).IntHeap[0]
		if max-min < res[1]-res[0] {
			res[0] = min
			res[1] = max
		}
	}
}