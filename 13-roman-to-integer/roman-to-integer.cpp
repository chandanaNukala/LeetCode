class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int res=0;
        for(int i=0;i<s.size();){
            if(map[s[i]]<map[s[i+1]]){
                res+= map[s[i+1]]-map[s[i]];
                i=i+2;  
            }
            else{
                res+=map[s[i]];
                i++;
            }
            
        }
        return res;
    }
};