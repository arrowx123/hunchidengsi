// 402_Remove_K_Digits
// greedy
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int idx = 0;
        string ans = "";
        while(k && idx < num.size()){
            if(!ans.size()) ans += num[idx ++];
            else if(ans.back() > num[idx]){
                ans.pop_back();
                k --;
            }
            else{
                ans.push_back(num[idx ++]);
            }
        }
        
        while(idx < num.size()) ans.push_back(num[idx ++]);
        while(k) {
            ans.pop_back();
            k --;
        }
        
        int i = 0;
        for(; i < ans.size(); i ++)
            if(ans[i] != '0')
                break;
        
        return ans.substr(i).size() ? ans.substr(i) : "0";
    }
};
