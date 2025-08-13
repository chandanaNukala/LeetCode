class Solution {
public:
    int trap(vector<int>& height) {
        // int ans=0;
        // for(int i=0;i<height.size();i++){
        //     int left_max=0,right_max=0;
        //     for(int j=i;j>=0;j--){
        //         left_max=max(left_max,height[j]);
        //     }
        //     for(int j=i;j<height.size();j++){
        //         right_max=max(right_max,height[j]);
        //     }
        //     ans+=min(left_max,right_max)-height[i];
        // }
        // return ans;

        int ans=0;
        int n=height.size();
        vector<int> left(n),right(n);
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=1;i<n-1;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};