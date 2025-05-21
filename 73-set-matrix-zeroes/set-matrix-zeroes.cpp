class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<pair<int,int>>vec;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(matrix[i][j]==0){
                vec.push_back({i,j});
            }
        }
    }
    for (const auto& p : vec) {
        int row = p.first;
        int col = p.second;

        // Set the entire row to 0
        for (int j = 0; j < cols; ++j) {
            matrix[row][j] = 0;
        }

        // Set the entire column to 0
        for (int i = 0; i < rows; ++i) {
            matrix[i][col] = 0;
        }
    }

}

};