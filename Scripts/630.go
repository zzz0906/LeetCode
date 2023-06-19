import (
	"container/heap"
	"fmt"
)

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

type MaxHeap struct {
	IntHeap
}

func (h MaxHeap) Less(i, j int) bool { return h.IntHeap[i] > h.IntHeap[j] }

func scheduleCourse(courses [][]int) int {
	//sort
	sort.Slice(courses, func(i, j int) bool {
		return courses[i][1] < courses[j][1]
	})
	//max heap
	h := &MaxHeap{}
	heap.Init(h)
	//current days
	days := 0
	for _, v := range courses {
		if days+v[0] <= v[1] {
			days += v[0]
			heap.Push(h, v[0])
		} else if h.Len() > 0 && v[0] < (*h).IntHeap[0] {
			days += v[0] - heap.Pop(h).(int)
			heap.Push(h, v[0])
		}
	}
	return h.Len()
}