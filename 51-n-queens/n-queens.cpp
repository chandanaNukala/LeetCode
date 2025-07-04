class Solution {
    vector<vector<string>>solutions;
    vector<string> createBoard(vector<vector<char>>board,int n){
        vector<string>chess;
        for(int row=0;row<n;row++){
            string current_row(board[row].begin(),board[row].end());
            chess.push_back(current_row);
        }
        return chess;
    }
    void backtrack(int row,unordered_set<int>& cols,unordered_set<int>& diagnol,unordered_set<int>& anti_diagnol,vector<vector<char>>board,int n){
        if(row==n){
            solutions.push_back(createBoard(board,n));
            return;
        }
        for(int col=0;col<n;col++){
            int cur_diagnol=row-col;
            int cur_anti_diagnol=row+col;

            if(cols.count(col) || diagnol.count(cur_diagnol) || anti_diagnol.count(cur_anti_diagnol)){
                continue;
            }
            cols.insert(col);
            diagnol.insert(cur_diagnol);
            anti_diagnol.insert(cur_anti_diagnol);
            board[row][col]='Q';
            backtrack(row+1,cols,diagnol,anti_diagnol,board,n);

            cols.erase(col);
            diagnol.erase(cur_diagnol);
            anti_diagnol.erase(cur_anti_diagnol);
            board[row][col]='.';
            
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        unordered_set<int>cols;
        unordered_set<int>diagnol;
        unordered_set<int>anti_diagnol;
        backtrack(0,cols,diagnol,anti_diagnol,board,n);
        return solutions;
    }
};