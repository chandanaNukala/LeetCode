class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>combined=nums1;
        combined.insert(combined.end(),nums2.begin(),nums2.end());
        sort(combined.begin(),combined.end());

        if(combined.size()%2==1){
            return static_cast<double>(combined[combined.size()/2]);
        }
        else{
            int m1=combined[combined.size()/2-1];
            int m2=combined[combined.size()/2];
            return (static_cast<double>(m1)+static_cast<double>(m2))/2.0;

        }
        
    }
};