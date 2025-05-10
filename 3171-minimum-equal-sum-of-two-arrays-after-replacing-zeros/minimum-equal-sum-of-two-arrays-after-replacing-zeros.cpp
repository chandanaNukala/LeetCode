class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
       

        long long cnt_nums1=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==0){
                nums1[i]=1;
                cnt_nums1++;
            }
        }
        long long cnt_nums2=0;
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]==0){
                nums2[i]=1;
                cnt_nums2++;
            }
        }
         long long nums1_sum=0;
        for(int i=0;i<nums1.size();i++){
            nums1_sum+=nums1[i];
        }
        long long nums2_sum=0;
        for(int i=0;i<nums2.size();i++){
            nums2_sum+=nums2[i];
        }
       
        if(nums1_sum>nums2_sum && cnt_nums2==0) return -1;
        if(nums1_sum<nums2_sum && cnt_nums1==0) return -1;

        

        return max(nums1_sum,nums2_sum);

    }
};