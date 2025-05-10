class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>combined=nums1;
        // combined.insert(combined.end(),nums2.begin(),nums2.end());
        // sort(combined.begin(),combined.end());

        // if(combined.size()%2==1){
        //     return static_cast<double>(combined[combined.size()/2]);
        // }
        // else{
        //     int m1=combined[combined.size()/2-1];
        //     int m2=combined[combined.size()/2];
        //     return (static_cast<double>(m1)+static_cast<double>(m2))/2.0;

        // }
        vector<int>&v1=nums1;
        vector<int>&v2=nums2;
        if(nums1.size()>nums2.size()){
            swap(v1,v2);
        }
        int n=nums1.size(),m=nums2.size();
        int l=0;
        int r=n;
        int total=n+m;
        int half=(total+1)/2;
        while(l<=r){
            int mid1= l+(r-l)/2;
            int mid2= half-mid1;

        
            int l1 = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
            int r1 = mid1 < nums1.size() ? nums1[mid1] : INT_MAX;
            int l2 = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
            int r2 = mid2 <  nums2.size() ? nums2[mid2] : INT_MAX;
            if(l1<=r2 && l2<=r1){
                if(total%2==1){
                    return max(l1,l2);
                }
                else{
                    return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
                }
            }
            else if(l1>r2){
                r=mid1-1;
            }
            else{
                l=mid1+1;
            }

        }
        return 0;

        
    }
};