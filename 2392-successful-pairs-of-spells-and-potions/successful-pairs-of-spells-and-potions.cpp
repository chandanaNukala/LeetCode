class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i=0;i<spells.size();i++){
        
            int l=0;
            int h=potions.size()-1;
           
            while(l<=h){
                int m=l+(h-l)/2;
                long long prod=(long long)spells[i]*(long long)potions[m];
                if(prod>=success){
                    h=m-1;
                  
                }
                else{
                    l=m+1;
                }
            }
         
            ans.push_back(potions.size()-l);
        
        }
        return ans;

    }
};