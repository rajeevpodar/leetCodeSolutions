// https://leetcode.com/problems/game-of-life/
// Taking O(m * n) space
class Solution {
    //left,leftDiagonal,top,rightDiagonal, right, rightBottomDiag, bottom, leftBottomDiag
    const vector<int> row {0,-1,-1,-1,0,1,1,1};
    const vector<int> col {-1,-1,0,1,1,1,0,-1};
    
    int getLiveCount(const vector<vector<int>>& board, int i, int j ) {
        int liveCounter = 0;
        const int rowSize = board.size();
        const int colSize = board[i].size();
        /*for(int k = 0 ; k < row.size(); k++) {
            if (  i + row[k] >= 0 && i + row[k] < rowSize
               && j + col[k] >= 0 && j + col[k] < colSize ) {
                liveCounter += board[i+row[k]][j+col[k]];
            }
        }*/
        //Another way to iterate on all 8 neighbours, including self
        for(int I = max(i-1,0); I < min(i+2,rowSize); I++) {
            for(int J = max(j-1,0); J < min(j+2,colSize); J++) {
                if ( I == i && j == J) {
                    continue;
                }
                
                liveCounter += board[I][J] <= 0 ? 0 : 1;
            }
        }
        return liveCounter;
    }
    
public:
    /**
    Board store only 0 & 1. We can store the states as follows:
    1. If cell was dead originally then we can store -1
    2. If cell was live originaly then we can store 2.
    3. Update the board as per the above values.
    4. Iterate again to update the required values.
    Live remain Live = 1
    Live becomes dead = 2
    Dead remain Dead = 0
    Dead becomes Live = -1
    **/
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0 ; i < board.size(); i++) {
            for(int j = 0 ; j < board[i].size(); j++) {
                int liveCount = getLiveCount(board, i, j);
                if ( board[i][j]) {
                    if ( liveCount < 2 || liveCount > 3) {
                        // Make it dead due to over population.
                        board[i][j] = 2;
                    }
                } else {
                    if ( liveCount == 3) {
                        board[i][j] = -1;
                    }
                }
            }
        }
        //Iterate again to update the required values.
        for(int i = 0 ; i < board.size(); i++) {
            for(int j = 0 ; j < board[i].size(); j++) {
                if ( board[i][j] == 2) {
                    board[i][j] = 0;
                } else if ( board[i][j] == -1) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
