class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
       priority_queue<int,vector<int>,greater<int>>pq;
       sort(intervals.begin(),intervals.end());
       int cnt=0;
       for(int i=0;i<intervals.size();i++){
        if(!pq.empty() && pq.top()<=intervals[i][0]){
            pq.pop();
        }
        pq.push(intervals[i][1]);
        cnt=max(cnt,(int)pq.size());
       }
       return cnt;
    }
};