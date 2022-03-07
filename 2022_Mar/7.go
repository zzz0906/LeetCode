/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {

	start := &ListNode{
		Val:  -200,
		Next: nil,
	}

	h := start

	for list1 != nil || list2 != nil {
		if list1 == nil {
			h.Next = list2
			break
		}
		if list2 == nil {
			h.Next = list1
			break
		}
		if list1.Val < list2.Val {
			h.Next, list1, h = list1, list1.Next, list1
		} else {
			h.Next, list2, h = list2, list2.Next, list2
		}
	}
	return start.Next
}