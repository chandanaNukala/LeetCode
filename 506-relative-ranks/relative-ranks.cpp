class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result(score.size()); 
        unordered_map<int,int>map;
        for(int i=0;i<score.size();i++){
            map[score[i]]=i;
        }
        sort(score.begin(),score.end(),greater<int>());
        for(int i=0;i<score.size();i++){
            if(i==0){
                result[map[score[i]]]="Gold Medal";
            }
            else if(i==1){
                result[map[score[i]]]="Silver Medal";
            }
            else if(i==2){
                result[map[score[i]]]="Bronze Medal";
            }
            else{
                result[map[score[i]]]=to_string(i+1);
            }
            
        }
        return result;

    }
};