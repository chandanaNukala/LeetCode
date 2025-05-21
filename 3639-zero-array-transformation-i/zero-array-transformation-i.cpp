class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    //    for (int i = 0 ; i < queries.size() ; i++) 
    //         for (int j = queries[i][0]; j <= queries[i][1]; j++) 
    //             if (nums[j] > 0) nums[j]--;
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]>0){
    //             return false;
    //         }
    //     }
    //     return true;
        vector<int>diff(nums.size()+1,0);
        for(const auto& q:queries){
            diff[q[0]]++;
            if(q[1]+1<nums.size()){
                diff[q[1]+1]--;
            }
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=diff[i];
            if(nums[i]>sum){
                return false;
            }
        }
        return true;
    }
};