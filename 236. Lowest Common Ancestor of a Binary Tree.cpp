/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/
//My Solution: 15ms
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return root;
		stack<TreeNode*> par_p;
		stack<TreeNode*> st;
		bool p_found = false, q_found = false;
		//bool used = false;
		TreeNode* cur=root,*parent=nullptr;
		while (cur || !st.empty()) {
			if (cur) {
				st.push(cur);
				if (!(p_found || q_found)) {
					par_p.push(cur);
					parent = cur;
				}
				if (cur == p) p_found = true;
				if (cur == q) q_found = true;
				if (p_found && q_found) return parent;
				cur = cur->left;
			}
			else {
				cur = st.top();
				st.pop();
				if (!par_p.empty() && cur == par_p.top()) {
					parent = par_p.top();
					par_p.pop();
				}
				cur = cur->right;
			}

		}
		return (p_found && q_found) ? parent : nullptr;
	}
};
//Solution 2: 15ms
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
	}
};