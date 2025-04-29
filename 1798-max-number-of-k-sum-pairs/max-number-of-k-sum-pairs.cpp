class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        int cnt=0;
        while(l<r){
            if(nums[l]+nums[r]==k){
                // nums.erase(nums.begin() + l);
                // nums.erase(nums.begin() + r);
                l++;
                r--;
                cnt++;
            }
            else if(nums[l]+nums[r]>k){
               r--;
            }
            else{
                l++;
            }
        }
        return cnt;

    }
};