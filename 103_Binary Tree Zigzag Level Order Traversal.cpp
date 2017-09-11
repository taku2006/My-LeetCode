/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Solution1: traverse the Binary Tree.
// Result: beat 26.77%
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q_nodes;
        vector<vector<int>> vec_seq;
        vector<int> vec_nodes;
        if(root == nullptr){
            return vec_seq;
        }
        q_nodes.push(root);
        bool reverse = 0;//0 means left to right, 1 means right to left
        while(!q_nodes.empty()){
            vec_nodes = zigzag_SingleLevel(q_nodes,reverse);
            vec_seq.push_back(vec_nodes);
            reverse = !reverse;
            vec_nodes.clear();
        }
        return vec_seq;
    }
    
    vector<int> zigzag_SingleLevel(queue<TreeNode*> &q,bool rev){
        vector<int> vec;
        TreeNode* it;
        int sz = q.size();
        int i=0;
        while(i<sz){
            it = q.front();
            q.pop();
            vec.push_back(it->val);
            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
            //q.pop();
            ++i;
        }
        
        if(rev){
            reverse(vec.begin(),vec.end());
        }
        
        return vec;
        
    }
};