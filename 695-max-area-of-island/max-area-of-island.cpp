class Solution {
    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    area=max(area,bfs(grid,r,c));
                }
            }
        }
        return area;
    }
    int bfs(vector<vector<int>>& grid,int r,int c){
        queue<pair<int,int>>q;
        grid[r][c]=0;
        q.push({r,c});
        
        int res=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row = node.first, col = node.second;
            for(auto d:directions){
                int tmp_r=row+d.first;
                int tmp_c=col+d.second;
                if(tmp_r<grid.size() && tmp_r>=0 && tmp_c<grid[0].size() && tmp_c>=0 && grid[tmp_r][tmp_c]==1){
                    grid[tmp_r][tmp_c]=0;
                    q.push({tmp_r,tmp_c});
                    res++;
                }
            }
        }
        return res;
    }
};