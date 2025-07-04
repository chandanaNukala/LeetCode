class Solution {
public:
    int findGCD(vector<int>& nums) {
        int l=INT_MAX;
        int h=0;
        for(int i=0;i<nums.size();i++){
            h=max(h,nums[i]);
            l=min(l,nums[i]);
        }
        int gcd=0;
        for(int i=1;i<=l;i++){
            if(l%i==0 && h%i==0){
                gcd=i;
            }
        }
        return gcd;
    }
};