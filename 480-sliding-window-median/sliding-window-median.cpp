class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        priority_queue<int>lo;
        priority_queue<int,vector<int>,greater<int>>hi;

        int i=0;
        while(i<k){
            lo.push(nums[i++]);
        }
        for(int j=0;j<k/2;j++){
            hi.push(lo.top());
            lo.pop();
        }

        vector<double>ans;

        while(true){
            if(k%2==0){
                ans.push_back(((double)lo.top()+(double)hi.top())*0.5);
            }
            else{
                ans.push_back(lo.top());
            }
            if(i>=nums.size()){
                break;
            }

            int out=nums[i-k];
            int in=nums[i++];
            int balance=0;

            if(out<=lo.top()){
                balance+=-1;
            }
            else{
                balance+=1;
            }
            map[out]++;
            
            if(!lo.empty() && in<=lo.top()){
                balance++;
                lo.push(in);
            }
            else{
                balance--;
                hi.push(in);
            }


            if(balance<0){
                lo.push(hi.top());
                hi.pop();
                balance++;
            }
            if(balance>0){
                hi.push(lo.top());
                lo.pop();
                balance--;
            }

            while(map[lo.top()]){
                map[lo.top()]--;
                lo.pop();
            }

            while(!hi.empty() && map[hi.top()]){
                map[hi.top()]--;
                hi.pop();
            }

        }
        return ans;
    }
};