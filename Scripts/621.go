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

func leastInterval(tasks []byte, n int) int {
	m := make(map[byte]int)
	for _, v := range tasks {
		m[v]++
	}
	h := &MaxHeap{}
	heap.Init(h)
	for _, v := range m {
		heap.Push(h, v)
	}
	res := 0
	for h.Len() > 0 {
		tmp := []int{}
		for i := 0; i <= n; i++ {
			if h.Len() > 0 {
				tmpv := heap.Pop(h).(int) - 1
				tmp = append(tmp, tmpv)
			}
			res++
			if h.Len() == 0 {
				break
			}
		}
		for _, v := range tmp {
			if v > 0 {
				heap.Push(h, v)
			}
		}
		if h.Len() > 0 {
			res += n + 1 - len(tmp)
		}
	}
	return res
}