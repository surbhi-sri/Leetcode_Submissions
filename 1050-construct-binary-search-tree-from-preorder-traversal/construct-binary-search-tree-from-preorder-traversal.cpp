/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void insert(TreeNode*& root, TreeNode* node) {}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i, n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < n; i++) {
            TreeNode* temp = root;
            TreeNode* node = new TreeNode(preorder[i]);
            while (temp) {
                if (node->val < temp->val) {
                    if (temp->left)
                        temp = temp->left;
                    else {
                        temp->left = node;
                        break;
                    }
                } else {
                    if (temp->right)
                        temp = temp->right;
                    else {
                        temp->right = node;
                        break;
                    }
                }
            }
        }

        return root;
    }
};