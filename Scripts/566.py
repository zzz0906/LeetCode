class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        if (len(mat)*len(mat[0]) != r*c):
            return mat
        mat = [item for sublist in mat for item in sublist]
        res = []
        for i in range(r):
            res.append([])
            for j in range(c):
                res[i].append(mat[i*c+j])
        return res