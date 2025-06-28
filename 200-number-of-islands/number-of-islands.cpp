class Solution {
  vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]=='1'){
                    // bfs(grid,r,c);
                    dfs(grid,r,c);
                    islands++;
                }
            }
        }
        return islands;
    }
     void dfs(vector<vector<char>>& grid,int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size()|| grid[r][c]=='0'){
            return;
        }
        grid[r][c]='0';
         for(const auto&d:directions ){
            dfs(grid,r+d.first,c+d.second);
         }
    }
    void bfs(vector<vector<char>>& grid,int r,int c){
        queue<pair<int,int>>q;
        grid[r][c]='0';
        q.push({r,c});

        while(!q.empty()){
            auto node=q.front();q.pop();
            int row=node.first,col=node.second;

            for(const auto&d:directions ){
                int row_temp=row+d.first;
                int col_temp=col+d.second;

                if(row_temp>=0 && row_temp<grid.size() && col_temp>=0 && col_temp<grid[0].size() && grid[row_temp][col_temp]=='1'){
                    q.push({row_temp,col_temp});
                    grid[row_temp][col_temp]='0';

                }
            }
        }
    }
};