// 750_Number_Of_Corner_Rectangles
// map
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int N = 0;
        unordered_map<int, vector<int>> umap;
        unordered_map<int, int> count;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++)
                if(grid[i][j]) {
                    umap[i].push_back(j);
                    N ++;                    
                }
        }
        
        int ans = 0;
        for(int i = 0; i < m; i ++){
            if(umap[i].size() >= sqrt(N)){
                unordered_set<int> uset;
                uset.insert(umap[i].begin(), umap[i].end());
                for(int j = 0; j < m; j ++){
                    if(j <= i && umap[j].size() >= sqrt(N))
                        continue;
                    int found = 0;
                    for(int k = 0; k < umap[j].size(); k ++){
                        if(uset.count(umap[j][k]))
                            found ++;
                    }
                    ans += found * (found - 1) / 2;
                }
            }
            else{
                for(int j = 0; j < umap[i].size(); j ++){
                    for(int k = j + 1; k < umap[i].size(); k ++){
                        ans += count[umap[i][j] * 201 + umap[i][k]];
                        count[umap[i][j] * 201 + umap[i][k]] ++;
                    }
                }
            }
        }
        return ans;
    }
};
