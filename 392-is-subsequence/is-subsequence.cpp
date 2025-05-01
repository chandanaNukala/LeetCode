class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1=0;
        for(int i=0;i<t.length();i++){
            if(s[l1]==t[i]){
                l1++;
            }
        }
        if(l1==s.length()){
            return true;
        }
        return false;
        
        
    }
};