/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func tree2str(root *TreeNode) string {
	if root == nil {
		return ""
	}
	res := strconv.Itoa(root.Val)
	if root.Left != nil {
		res += "(" + tree2str(root.Left) + ")"
	}
	if root.Right != nil {
		if root.Left == nil {
			res += "()"
		}
		res += "(" + tree2str(root.Right) + ")"
	}
	return res
}