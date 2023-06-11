/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(root *TreeNode, depth int, val int) {
	if root == nil {
		return
	}
	if depth == 1 {
		root.Left = &TreeNode{val, root.Left, nil}
		root.Right = &TreeNode{val, nil, root.Right}
		return
	}
	dfs(root.Left, depth-1, val)
	dfs(root.Right, depth-1, val)
}
func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
	if depth == 1 {
		return &TreeNode{val, root, nil}
	}
	dfs(root, depth-1, val)
	return root
}	