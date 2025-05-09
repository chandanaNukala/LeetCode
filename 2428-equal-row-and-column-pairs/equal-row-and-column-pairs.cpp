class Solution {
public:
   
    int equalPairs(vector<vector<int>>& grid) {


       
        int ans=0;
        map<vector<int>,int>mp;
        for(int i=0;i<grid.size();i++){
            mp[grid[i]]++;
        }
        for(int j=0;j<grid.size();j++){
            vector<int>temp;
            for(int i=0;i<grid.size();i++){
                temp.push_back(grid[i][j]);
            }
            ans+=mp[temp];
        }
        return ans;


    }
};