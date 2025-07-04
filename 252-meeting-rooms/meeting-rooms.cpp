class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
       if(intervals.size()==0)return true;
        sort(intervals.begin(),intervals.end());
        int l=intervals[0][0];
        int r=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<r){
                return false;
            }
            r=intervals[i][1];
        }
        return true;
    }
};