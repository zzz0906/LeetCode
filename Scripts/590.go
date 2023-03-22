/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */
func dfs(cur *Node, res *[]int) {
	if cur == nil {
		return
	}
	for _, child := range cur.Children {
		dfs(child, res)
	}
	*res = append(*res, cur.Val)
}
func postorder(root *Node) []int {
	res := []int{}
	dfs(root, &res)
	return res
}