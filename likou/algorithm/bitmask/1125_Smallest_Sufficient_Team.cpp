// 1125_Smallest_Sufficient_Team
// bitmask
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& ss, vector<vector<string>>& p) {
        unordered_map<string, int> umap;
        vector<int> ps(p.size());
        for(int i = 0; i < ss.size(); i ++) umap[ss[i]] = i;
        for(int i = 0; i < p.size(); i ++){
            for(int j = 0; j < p[i].size(); j ++)
                ps[i] |= (1 << umap[p[i][j]]);
        }
        
        vector<int> dp((1 << ss.size()), p.size() + 10);
        vector<pair<int, int>> parent(1 << ss.size());
        dp[0] = 0;
        
        for(int i = 0; i < p.size(); i ++){
            for(int j = (1 << ss.size()) - 1; j >= 0; j --){
                if(dp[j | ps[i]] > dp[j] + 1){
                    dp[j | ps[i]] = dp[j] + 1;
                    parent[j | ps[i]] = {j, i};
                }
            }
        }
        
        vector<int> ans;
        int state = (1 << ss.size()) - 1;
        while(state){
            ans.push_back(parent[state].second);
            state = parent[state].first;
        }
        
        return ans;
    }
};
