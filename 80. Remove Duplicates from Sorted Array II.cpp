//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if ( nums.size() > 2) {
            /**
            PseudoCode:
            1. Idea here is to keep a pointer which need to be modified in case of more
            than 2 elements exisitence.
            2. Current Element need to be compared with kth position i.e. 2 in our case,
            before the index(to be modified, just in case) is there is a mis-match update
            current index value. else move on with i
            
            **/
            int index = 2;
            for(int i = 2; i < nums.size(); i++) {
                if ( nums[index-2] != nums[i] ) {
                    nums[index++] = nums[i];
                }
            }
            length = index;
        }
        return length;
    }
};
