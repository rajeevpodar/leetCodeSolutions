//https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    
    bool isValid(const vector<vector<char>>& board, const int sI, const int sJ) {
        /**
        Assumption: sI & sJ will be valid always.
        PseudoCode: Splits the problem in 3 parts.
            1. Check in row
            2. Check in column
            3. Check in sub matrix.
        **/
        bool result = true;
        
        vector<int> counter(9,0);
        
        // Check column for given index.
        for(int j = 0 ; j < board[sI].size() && result; j++) {
            if ( board[sI][j] != '.') {
                counter[board[sI][j] - '1']++;
                result = counter[board[sI][j] - '1'] > 1 ? false : true;
            }
        }
        
        counter.assign(9,0);
        // Check row for given index.
        for(int i = 0 ; i < board.size() && result; i++) {
            if ( board[i][sJ] != '.') {
                counter[board[i][sJ] - '1']++;
                result = counter[board[i][sJ] - '1'] > 1 ? false : true;
            }
        }
        
        counter.assign(9,0);
        //Check subMatrix of size 3X3.
        for(int i = (sI/3) * 3; i < ((sI/3)*3) + 3 && result; i++) {
            for(int j = (sJ/3) * 3; j < ((sJ/3)*3) + 3 && result; j++) {
                if ( board[i][j] != '.') {
                    counter[board[i][j] - '1']++;
                    result = counter[board[i][j] - '1'] > 1 ? false : true;
                }
            }
        }       
        
        return result;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < board.size(); i++) {
            for(int j = 0; j < board.size(); j++) {
                if ( board[i][j] != '.' && !isValid(board,i,j)) {
                    return false;                   
                }
            }
        }
        return true;
    }
};
