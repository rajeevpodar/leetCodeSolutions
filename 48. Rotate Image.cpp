//https://leetcode.com/problems/rotate-image/submissions/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int startIndex = 0;
        int endIndex = 0;
        /**
        PseudoCode: This is a standard problem of rotating an image by 90 degree.
        1. We need to transpose the matrix.
        2. Reverse each row.
        **/
        // First transpose the matrix.
        for(int i = 0 ; i < matrix.size(); i++) {
            for(int j = 0 ; j < i ; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Now we need to reverse each row.
        for(int i = 0 ; i < matrix.size(); i++){
            int start = 0 ; 
            int end = matrix.size() - 1;
            while ( start < end) {
                swap(matrix[i][start++], matrix[i][end--]);
            }
        }
    }
};
