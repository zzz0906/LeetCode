/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(root *TreeNode, level int, sum *[]float64, count *[]int) {
	if root == nil {
		return
	}
	if len(*sum) <= level {
		*sum = append(*sum, 0)
		*count = append(*count, 0)
	}
	(*sum)[level] += float64(root.Val)
	(*count)[level]++
	dfs(root.Left, level+1, sum, count)
	dfs(root.Right, level+1, sum, count)
}
func averageOfLevels(root *TreeNode) []float64 {
	sum := make([]float64, 0)
	count := make([]int, 0)
	dfs(root, 0, &sum, &count)
	for i := 0; i < len(sum); i++ {
		sum[i] /= float64(count[i])
	}
	return sum
}