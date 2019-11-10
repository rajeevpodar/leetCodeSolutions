//https://leetcode.com/contest/weekly-contest-162/problems/reconstruct-a-2-row-binary-matrix/
class Solution {
    
    int getUpperSum(const vector<vector<int>>& data) {
        int upperSum = 0;
        for(int j= 0; j < data[0].size(); j++) {
            upperSum += data[0][j];
        }
        return upperSum;
    }
    int getLowerSum(const vector<vector<int>>& data) {
        int lowerSum = 0;
        for(int j= 0; j < data[1].size(); j++) {
            lowerSum += data[1][j];
        }
        return lowerSum;
    }
    
public:
    /**
    Since we have only two rows.
    So wherever colsum is 2 fill those both cells on as 1.
    Check if upper and lower is bigger then expected then result is not possible.
    Else fill with greedy approach for the cell containing 0.
    **/
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> result;
        vector<vector<int>> data(2);
        for(int i = 0 ; i < data.size(); i++) {
            data[i].resize(colsum.size(),0);
        }
        
        // Fill each column which has sum two.
        for(int j= 0 ; j < colsum.size(); j++) {
            if ( colsum[j] == 2) {
                data[0][j] = 1;
                data[1][j] = 1;
            }
        }
        
        int upperSum = getUpperSum(data) - upper;
        int lowerSum = getLowerSum(data) - lower;
        // Still result might be possible. Try greedy apporach to fill all colSum 1.
        if ( upperSum <= 0 && lowerSum <= 0) {
            bool resultFound = true;
            for(int j= 0 ; j < colsum.size(); j++) {
                if ( colsum[j] == 1) {
                    if ( upperSum < 0) {
                        data[0][j] = 1;
                        upperSum += 1;
                    } else if (lowerSum < 0) {
                        data[1][j] = 1;
                        lowerSum += 1;
                    } else {
                        resultFound = false;
                        break;
                    }
                }
            }
            if ( resultFound && getUpperSum(data) == upper && getLowerSum(data) == lower) {
                result = data;
            }

        }    
        return result;
    
    }
};
