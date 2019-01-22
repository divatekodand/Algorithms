/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BST {
public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int kth_smallest = 0;
        bool found = kthSmallestHelper(root, k, counter, kth_smallest);
        return kth_smallest;
    }

private:
    bool kthSmallestHelper(TreeNode* root, int k, int& counter, int& kth_smallest){
        if(root != nullptr){
            bool found = kthSmallestHelper(root->left, k, counter, kth_smallest);
            if(found){
                return true;
            }
            counter++;
            if(counter == k){
                kth_smallest = root->val;
                return true;
            }            
            bool found2 = kthSmallestHelper(root->right, k, counter, kth_smallest);
            if(found2){
                return true;
            }
            return false;
        }
        else{
            return false;
        }
    }
};
