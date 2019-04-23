// 844_Backspace_String_Compare
// simulation
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int p1 = S.size();
        int p2 = T.size();
        int skip1 = 0;
        int skip2 = 0;
        while(p1 >= 0 || p2 >= 0){
            while(p1 >= 0){
                if(S[p1] == '#'){
                    skip1 ++;
                    p1 --;
                }
                else if(skip1 > 0){
                    skip1 --;
                    p1 --;
                }
                else
                    break;
            }
            while(p2 >= 0){
                if(T[p2] == '#'){
                    skip2 ++;
                    p2 --;
                }
                else if(skip2 > 0){
                    skip2 --;
                    p2 --;
                }
                else
                    break;
            }
            
            if(p1 >= 0 && p2 >= 0){
                if(S[p1] != T[p2])
                    return false;
            }
            
            if(p1 >= 0 ^ p2 >= 0)
                return false;
            
            p1 --;
            p2 --;
        }
        return true;
    }
};
