class Solution {
public:
    int trap(vector<int>& height) {
        // int max_l=height[0];
        // int max_r=height[height.size()-1];
        // int l=0;
        // int r=height.size()-1;
        // int ans=0;
        // while(l<r){
        //     if(max_l<=max_r){
        //         ans+=max_l-height[l];
        //         l++;
        //         max_l=max(max_l,height[l]);
        //     }
        //     else{
        //         ans+=max_r-height[r];
        //         r--;
        //         max_r=max(max_r,height[r]);
        //     }
        // }
        // return ans;

        int ans=0;
        int ptr=0;
        stack<int>st;
        while(ptr<height.size()){
            while(!st.empty() && height[ptr]>height[st.top()]){
                int top=st.top();
                st.pop();
                if(st.empty()) break ; //for edge cases
                int dist=ptr-st.top()-1;  // distance between left and right of popped
                ans+= dist*(min(height[ptr],height[st.top()])-height[top]);
             }
             st.push(ptr++);
        }
        return ans;
    }
};