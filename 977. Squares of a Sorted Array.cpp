//https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        //Find the first non negative number,
        // and then consider them as two different array which need to be merged.
        int positiveIndex = 0;
        for(; positiveIndex < A.size(); ++positiveIndex) {
            if ( A[positiveIndex] > 0 ) {
                break;
            }
        }
        
        int negativeIndex = positiveIndex - 1;
        
        while(negativeIndex >= 0 && positiveIndex < A.size()) {
            if ( abs(A[negativeIndex]) < A[positiveIndex] ) {
                result.push_back( A[negativeIndex] * A[negativeIndex]);
                --negativeIndex;
            } else {
                result.push_back( A[positiveIndex] * A[positiveIndex]);
                ++positiveIndex;
            }
        }
        
        // Fill rest of the pending items.
        while( negativeIndex >= 0) {
            result.push_back( A[negativeIndex] * A[negativeIndex]);
            --negativeIndex;
        }
        // Fill rest of the pending items.
        while( positiveIndex < A.size()) {
            result.push_back( A[positiveIndex] * A[positiveIndex]);
            ++positiveIndex;
        }
        return result;       
    }
};
