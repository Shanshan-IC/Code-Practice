class Solution {
public:
    vector<TreeNode*> help_tree(int first, int last) {
        vector<TreeNode*> res;
        for (int root=first; root<last+1; root++) {
            auto left = root==first ? vector<TreeNode*>{nullptr}:help_tree(first, root-1);
            auto right = root==last ? vector<TreeNode*>{nullptr}:help_tree(root+1, last);
            for (auto l:left)
                for (auto r:right) {
                    TreeNode *node = new TreeNode(root);
                    node -> left = l;
                    node -> right = r;
                    res.push_back(node);
                }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return help_tree(1, n);
    }
};