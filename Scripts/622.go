type MyCircularQueue struct {
	arr  []int
	size int
	head int
	tail int
}

func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		arr:  make([]int, k+1),
		size: k + 1,
		head: 0,
		tail: 0,
	}
}

func (this *MyCircularQueue) EnQueue(value int) bool {
	if this.tail-this.head == this.size-1 || this.tail-this.head == -1 {
		return false
	}
	this.tail = (this.tail + 1) % this.size
	this.arr[this.tail] = value
	return true
}

func (this *MyCircularQueue) DeQueue() bool {
	if this.tail == this.head {
		return false
	}
	this.head = (this.head + 1) % this.size
	return true
}

func (this *MyCircularQueue) Front() int {
	if this.tail == this.head {
		return -1
	}
	return this.arr[(this.head+1)%this.size]
}

func (this *MyCircularQueue) Rear() int {
	if this.tail == this.head {
		return -1
	}
	return this.arr[this.tail]
}

func (this *MyCircularQueue) IsEmpty() bool {
	return this.tail == this.head
}

func (this *MyCircularQueue) IsFull() bool {
	return this.tail-this.head == this.size-1 || this.tail-this.head == -1
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.EnQueue(value);
 * param_2 := obj.DeQueue();
 * param_3 := obj.Front();
 * param_4 := obj.Rear();
 * param_5 := obj.IsEmpty();
 * param_6 := obj.IsFull();
 */ 