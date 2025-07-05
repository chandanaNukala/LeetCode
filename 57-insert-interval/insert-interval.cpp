class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int l=0;
        int r=intervals.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(intervals[mid][0]>newInterval[0]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        // if(intervals.size()%2==0){
        //     intervals.insert(intervals.begin() + l, newInterval);
        // }
        // else{
        //     intervals.insert(intervals.begin() + l+1, newInterval);
        // }
        intervals.insert(intervals.begin() + l, newInterval);
        
        vector<vector<int>>merged;
        for(int i=0;i<intervals.size();i++){
            if(merged.empty() || merged.back()[1]<intervals[i][0]){
                merged.push_back(intervals[i]);
            }
            else{
                merged.back()[1]=max(merged.back()[1],intervals[i][1]);
            }
        }
        return merged;
    }
};