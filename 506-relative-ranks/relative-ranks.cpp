class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result(score.size()); 
        // unordered_map<int,int>map;
        // for(int i=0;i<score.size();i++){
        //     map[score[i]]=i;
        // }
        // sort(score.begin(),score.end(),greater<int>());
        // for(int i=0;i<score.size();i++){
        //     if(i==0){
        //         result[map[score[i]]]="Gold Medal";
        //     }
        //     else if(i==1){
        //         result[map[score[i]]]="Silver Medal";
        //     }
        //     else if(i==2){
        //         result[map[score[i]]]="Bronze Medal";
        //     }
        //     else{
        //         result[map[score[i]]]=to_string(i+1);
        //     }
            
        // }
        // return result;
        priority_queue<pair<int,int>>PQ;
        for(int i=0;i<score.size();i++){
            PQ.push({score[i],i});
        }

        int rank=1;
        while(!PQ.empty()){
            auto top=PQ.top();
            PQ.pop();

            if(rank==1) result[top.second]="Gold Medal";
            else if(rank==2) result[top.second]="Silver Medal";
            else if(rank==3) result[top.second]="Bronze Medal";
            else result[top.second]=to_string(rank);
            rank++;
        }
        return result;

    }
};