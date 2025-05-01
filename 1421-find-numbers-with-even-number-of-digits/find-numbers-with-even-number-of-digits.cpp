class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int cnt_digit=0;
            while(num!=0){
                num=num/10;
                cnt_digit++;
            }
            if(cnt_digit%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};