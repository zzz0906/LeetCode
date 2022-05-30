/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(root *TreeNode, sum *int) {
	if root == nil {
		return
	}
	dfs(root.Right, sum)
	root.Val += *sum
	*sum = root.Val
	dfs(root.Left, sum)
}
func convertBST(root *TreeNode) *TreeNode {
	var sum *int
	sum = new(int)
	*sum = 0
	dfs(root, sum)
	return root
}