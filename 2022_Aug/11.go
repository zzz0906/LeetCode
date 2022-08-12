/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}
func max(x int, y int) int {
	if x > y {
		return x
	}
	return y
}
func get_min_max(root *TreeNode) (int, int, bool) {
	valid := true
	var leftmin, leftmax, rightmin, rightmax int
	var leftvalid, rightvalid bool
	leftmin = math.MaxInt32
	rightmin = math.MaxInt32
	leftmax = math.MinInt32
	rightmax = math.MinInt32

	if root.Left != nil {
		leftmin, leftmax, leftvalid = get_min_max(root.Left)
		if !leftvalid {
			valid = false
		}
		if leftmax >= root.Val {
			valid = false
		}
	}
	if root.Right != nil {
		rightmin, rightmax, rightvalid = get_min_max(root.Right)
		if !rightvalid {
			valid = false
		}
		if rightmin <= root.Val {
			valid = false
		}
	}
	return min(root.Val, min(leftmin, rightmin)), max(root.Val, max(leftmax, rightmax)), valid
}
func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	_, _, valid := get_min_max(root)
	return valid
}