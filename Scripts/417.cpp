#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;  
        }
    };
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int height = 0,width = 0;
    vector<vector<int>> new_height;
    unordered_map<pair<int,int>, pair<bool,bool>, pair_hash> records;


    void dfs(pair<int, int> cur, bool & pac, bool & aln, vector<vector<bool>> flag){
        if (records.count(cur)){
            pac = records[cur].first;
            aln = records[cur].second;
            return;
        }
        flag[cur.first][cur.second] = true;
        bool final_pac = false;
        bool final_aln = false;
        for (int i = 0; i < 4; i++){
            new_x = cur.first + dir[i][0];
            new_y = cur.second + dir[i][1];
            if (new_x < 0 || new_y < 0){
                final_pac = true;
            }else if (new_x >= width || new_y >= height){
                final_aln = true;
            }else if (height[new_x][new_y] <= heigth[cur.first][cur.second] && flag[new_x][new_y] == false){
                dfs(new_x, new_y, pac, aln);
                final_pac = final_pac | pac;
                final_aln = final_aln | final_aln;
            }
        }
        pac = final_pac;
        aln = final_aln;
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        width = heighs.size();
        height = heights[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < width; i++)
            for (int j = 0; j < height; j++){
                vector<vector<bool>> flag(width, vector<bool>(height,false));
                bool pac = false,aln = false;
                dfs(make_pair(i,j),pac,aln,flag);
                records[make_pair(i,j)] = make_pair(pac,aln);
                if (pac && aln){
                    res.push_back({i,j});
                }
            }
        return res;
        
    }
};