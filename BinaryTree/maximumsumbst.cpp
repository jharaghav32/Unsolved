// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  *///
//We know that for a Tree to BST the max of root->lef subtree should be less than the value of root
// and min of right sub tree should be greater than root->value so here we store the range to find it is a bst or not
// class Solution {
// public:
// here we take a vector which store the min , max  and sum of subtree
//     //here we create a vector which store the range of node and its sum;
//     vector<int> traversal(TreeNode* root,int & ans){
//         if(root==NULL) return {INT_MAX,INT_MIN,0};  // here we consider the null also as bst so in place of min
//and max value we return largest max and largest min so that its parent is always satisfies the condition
// root->val should be greater than max of left  and less than min of right(it is largest max and min so it always
//satisfies condition)
//         vector<int> lefttrav=traversal(root->left,ans); // we traverse for left  and right subtree and store its
// range and sum;
//         vector<int> righttrav=traversal(root->right,ans);
//         if( lefttrav[1]>=root->val || righttrav[0]<=root->val)return {INT_MIN,INT_MAX,0}; // if this condition
//satisfies it means that then tree is not bst because here max of left is greater than root->val and othr case also
//         int currsum = lefttrav[2]+righttrav[2]+root->val;
//         ans = max(ans,currsum);
//         return {min(lefttrav[0],root->val),max(righttrav[1],root->val),currsum};
//     }
//     int maxSumBST(TreeNode* root) {
//        int ans=INT_MIN;
//         traversal(root,ans);
//         return max(0,ans);
//     }
// };