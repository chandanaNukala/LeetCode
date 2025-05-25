class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>map;
        for(int i=0;i<words.size();i++){
            map[words[i]]++;
        }
        int ans=0;
        bool odd=false;
        for(auto it:map){
            string rev= string{it.first[1],it.first[0]};

            if(it.first==rev){
                ans+=(it.second/2)*4;
                if(it.second%2==1){
                    odd=true;
                }
            }
            else if(map.count(rev)){
                ans+= min(it.second,map[rev])*4;
                map[rev]=0;
                
            }
        }
        if(odd) ans+=2;
        return ans;
    }
};