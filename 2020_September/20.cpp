class Solution {
public:
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ans;
    int edx, edy;
    vector<vector<int>> subgrid;
    void dfs(int currentx, int currenty, unordered_set<pair<int, int>,pair_hash> pastway){
        if (currentx == edx && currenty == edy) {
            ans++; return;
        }
        for (int i = 0; i < 4; i++){
                if (currentx + dir[i][0] >= 0 && currentx + dir[i][0] < subgrid.size() && currenty + dir[i][1] >= 0 && currenty + dir[i][1] < subgrid[0].size() && subgrid[currentx + dir[i][0]][currenty + dir[i][1]] != -1 && pastway.count(make_pair(currentx + dir[i][0],currenty+dir[i][1])) == 0){ 
                    cout<<1<<endl;
                    unordered_set<pair<int,int>,pair_hash> tmp = pastway; tmp.insert(make_pair(currentx + dir[i][0],currenty + dir[i][1]));
                    dfs(currentx + dir[i][0],currenty + dir[i][1],tmp);
                }
                //cout<<pastway.count(make_pair(currentx + dir[i][0],currenty+dir[i][1]))<<endl;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        subgrid = grid;
        int stx, sty;
        ans = 0;
        for (int i = 0; i < grid.size();i++)
            for (int j = 0; j < grid[i].size();j++){
                if (grid[i][j] == 1){
                    stx = i; sty = j;
                }
                if (grid[i][j] == 2){
                    edx = i; edy = j;
                }
            }
        unordered_set<pair<int,int>,pair_hash> tmp; 
        tmp.insert(make_pair(stx, sty));
        dfs(stx, sty,tmp);
        return ans;
    }
};