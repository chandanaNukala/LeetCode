class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         queue<pair<int,int>>q;
        int time=0;
        int fresh=0;

        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1){
                    fresh++;
                }
                if(grid[r][c]==2){
                    q.push({r,c});
                }
            }
        }
        vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
        while(fresh>0 && !q.empty()){
            int l=q.size();
            for(int i=0;i<l;i++){
                auto cur=q.front();
                q.pop();

                int r=cur.first;
                int c=cur.second;

                for(const auto&d:directions ){
                    int row=r+d.first;
                    int col=c+d.second;
                    if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col]==1){
                        grid[row][col]=2;
                        q.push({row,col});
                        fresh--;
                    }
                }


            }
            time++;

        }

        return fresh==0?time:-1;
    
    }
};