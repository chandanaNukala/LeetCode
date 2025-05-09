class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        vector<int>vec(gain.size()+1,0);
      
        for(int i=1;i<=gain.size();i++){
            vec[i]=vec[i-1]+gain[i-1];
        }
        
        int max_ans=INT_MIN;
        for(auto i:vec){
            max_ans=max(max_ans,i);
        }
        return max_ans;
    }
};