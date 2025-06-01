class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal;
        vector<int>prev;
        for(int i=0;i<=rowIndex;i++){
            vector<int>cur(i+1,1);

            for(int j=1;j<i;j++){
                cur[j]=prev[j-1]+prev[j];
            }
            pascal=cur;
            // pascal.push_back(cur);
            prev=cur;
            
        }
        return pascal;
    }
};