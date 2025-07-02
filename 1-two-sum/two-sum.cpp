class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {-1,-1};
        unordered_map<int,int>map;
    
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end()){
                return {i,map[target-nums[i]]};
            }
            map[nums[i]]=i;
        }
        return {-1,-1};

    }
};