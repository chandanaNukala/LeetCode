class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>PQ;
        for(int i=0;i<nums.size();i++){
            PQ.push(nums[i]);
            if(PQ.size()>k){
                PQ.pop();
            }
        }
        return PQ.top();
    }
};