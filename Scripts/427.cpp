/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        //check
        int last = grid[0][0];
        bool same = true;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++){
                if (last != grid[i][j]){
                    same = false;
                    break;
                }
            }
        if (same){
            Node* res = new Node(last, true);
            return res
        }
        //split
        int x1 = 0, y1 = 0; vector<vector<int>> split1;
        int x2 = 0, y2 = grid.size()/2; vector<vector<int>> split2;
        int x3 = grid.size()/2, y3 = 0; vector<vector<int>> split3;
        int x4 = grid.size()/2, y4 = grid.size()/2; vector<vector<int>> split4;
        for (int i = 0; i < grid.size()/2; i++){
            vector<int> tmp1; vector<int> tmp2; vector<int> tmp3; vector<int> tmp4;
            for (int j = 0; j < grid.size()/2; j++){
                tmp1.push_back(grid[x1 + i][y1 + j]);
                tmp2.push_back(grid[x2 + i][y2 + j]);
                tmp3.push_back(grid[x3 + i][y3 + j]);
                tmp4.push_back(grid[x4 + i][y4 + j]);
            }
            split1.push_back(tmp1); split2.push_back(tmp2); split3.push_back(tmp3); split4.push_back(tmp4);
        }
        return (new Node(last,false,construct(split1), construct(split2), construct(split3), construct(split4)));
    }
};