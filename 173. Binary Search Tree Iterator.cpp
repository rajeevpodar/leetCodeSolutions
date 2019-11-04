// https://leetcode.com/problems/binary-search-tree-iterator/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> _myStack;
    void updateLeftChildren(TreeNode* root) {
        if ( root ) {
            _myStack.push(root);
            updateLeftChildren(root->left);
        }        
    }
public:
    BSTIterator(TreeNode* root) {
        updateLeftChildren(root);
    }
    
    /** @return the next smallest number */
    int next() {
        auto result = _myStack.top();
        _myStack.pop();
        updateLeftChildren(result->right);
        return result->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_myStack.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
