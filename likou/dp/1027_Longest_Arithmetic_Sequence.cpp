// dp
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int ans = INT_MIN;
        unordered_map<int, unordered_map<int, int>> umap;
        for(int i = 0; i < A.size(); i ++){
            for(int j = 0; j < i; j ++){
                int diff = A[i] - A[j];
                if(umap[j][diff]){
                    umap[i][diff] = umap[j][diff] + 1;
                }
                else{
                    umap[i][diff] = 2;
                }
                ans = max(ans, umap[i][diff]);
            }
        }
        return ans;
    }
};
