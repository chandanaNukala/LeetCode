class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>>q;
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[0].size();j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
            for(auto d:directions){
                int row=node.first+d.first;
                int col=node.second+d.second;
                if(row<rooms.size() && row>=0 && col<rooms[0].size() && col>=0 && rooms[row][col]==INT_MAX ){
                    rooms[row][col]=rooms[node.first][node.second]+1;
                    q.push({row,col});
                }
            }
        }

    }
};