

func min(x int, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}
func abs(x int) int {
	if x < 0 {
		return -1 * x
	} else {
		return x
	}
}
func getMinimumDifference(root *TreeNode) int {
	var res = 100000
	var dfs func(root *TreeNode)
	dfs = func(root *TreeNode) {
		if root != nil {
			if root.Left != nil {
				var tmp = root.Left
				for tmp.Right != nil {
					tmp = tmp.Right
				}
				res = min(res, abs(tmp.Val-root.Val))
				dfs(root.Left)
			}
			if root.Right != nil {
				var tmp = root.Right
				for tmp.Left != nil {
					tmp = tmp.Left
				}
				res = min(res, abs(tmp.Val-root.Val))
				dfs(root.Right)
			}
		}
	}
	dfs(root)
	return res
}