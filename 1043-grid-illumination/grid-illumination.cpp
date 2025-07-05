class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        unordered_map<int,int>diagnols;
        unordered_map<int,int>anti_diagnols;
        unordered_map<int,int>rows;
        unordered_map<int,int>cols;
        set<pair<int, int>> activeLamps;
        
        for(int i=0;i<lamps.size();i++){
            int row=lamps[i][0];
            int col=lamps[i][1];
            int cur_diagnol=row-col;
            int cur_anti_diagnol=row+col;
            if (activeLamps.count({row, col})) continue;
            activeLamps.insert({row, col});
            rows[row]++;
            cols[col]++;
            diagnols[cur_diagnol]++;
            anti_diagnols[cur_anti_diagnol]++;

        }
        vector<pair<int, int>> directions = {
            {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };
        vector<int>res;
        for(int i=0;i<queries.size();i++){
            int r=queries[i][0];
            int c=queries[i][1];
            if(rows.count(r) >0|| cols.count(c) >0|| diagnols.count(r-c) >0|| anti_diagnols.count(r+c)>0 ){
               res.push_back(1);      
            }
            else{
                res.push_back(0);
            }

            for (const auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;
    
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                if (activeLamps.count({nr, nc})) {
                    activeLamps.erase({nr, nc});
                    if (--rows[nr] == 0) rows.erase(nr);
                    if (--cols[nc] == 0) cols.erase(nc);
                    if (--diagnols[nr - nc] == 0) diagnols.erase(nr - nc);
                    if (--anti_diagnols[nr + nc] == 0) anti_diagnols.erase(nr + nc);
                }
            }

         }
           
    return res;

    }
};