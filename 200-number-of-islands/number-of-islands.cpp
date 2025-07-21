class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]=='1'){
                    bfs(r,c,grid);
                    islands++;
                }
               
            }
        }
        return islands;
    }
    void bfs(int r,int c,vector<vector<char>>& grid){
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c]='0';
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;
            vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
            for(auto d:dir){
                int temp_row=row+d.first;
                int temp_col=col+d.second;
                if(temp_row<grid.size() && temp_row>=0 && temp_col<grid[0].size() && temp_col>=0 && grid[temp_row][temp_col]=='1'){
                    q.push({temp_row,temp_col});
                    grid[temp_row][temp_col]='0';
                }
            }
        }
    }
};