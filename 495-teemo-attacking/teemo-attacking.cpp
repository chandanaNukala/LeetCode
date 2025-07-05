class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=0;
        vector<vector<int>> ts;
        for(int i=0;i<timeSeries.size();i++){
            ts.push_back({timeSeries[i],timeSeries[i]+duration-1});
        }
       vector<vector<int>>merged;
        for(int i=0;i<ts.size();i++){
            if(merged.empty() || merged.back()[1]<ts[i][0]){
                merged.push_back(ts[i]);
            }
            else{
                merged.back()[1]=max( merged.back()[1],ts[i][1]);
            }
        }
        for(int i=0;i<merged.size();i++){
            ans+=(merged[i][1]-merged[i][0]+1);
        }
        return ans;
    }
};