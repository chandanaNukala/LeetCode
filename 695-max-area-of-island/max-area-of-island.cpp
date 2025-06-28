class Solution {
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    area=max(area,dfs(grid,r,c));
                }
            }
        }
        return area;
    }
    int dfs(vector<vector<int>>& grid, int r, int c) {
      
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1) {
            return 0;
        }

        grid[r][c] = 0; 
        int res=1;

        for(const auto& d : directions) {
            int new_r = r + d.first;
            int new_c = c + d.second;
            res+=dfs(grid, new_r, new_c);
        }
        return res;
    }
};