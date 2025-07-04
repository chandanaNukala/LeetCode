class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int>start;
        vector<int>end;
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int s=0;
        int e=0;
        int count=0;
        int ans=0;
        while(s!=intervals.size()){
            if(start[s]<end[e]){
                s++;
                count++;
                
            }
            else{
                e++;
                count--;
            }
            ans=max(ans,count);
        }
        return ans;

    }
};