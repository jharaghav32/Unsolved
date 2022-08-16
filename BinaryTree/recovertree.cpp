// // problem link:https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/submissions/
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
//  */
// class Solution {
// public:
// yaha pe hamne ek map bna liya jisme level wise ek ek element aata agar upper level hai present to wo es level 
// ka parent hoga so upper level ke left if not available than right me ye node insert kr dete hai
// every time the another node at same level get override and if left child is inserted we push the right one .
//     TreeNode* recoverFromPreorder(string traversal) {
//         unordered_map<int,TreeNode*>ump;
//         int dash=0;
//         for(int i=0;i<traversal.size();i++){
//             if(traversal[i]=='-')dash++;
//             else{
//                  string ans="";
//                 int start=i;
//                 while(i<traversal.size()&& isdigit(traversal[i]))
//                   i++;
//                 i--;
                
//                 int value = stoi(traversal.substr(start,i-start+1));
//                 ump[dash]= new TreeNode(value);
//                 if(dash){
//                     if(ump[dash-1]->left)
//                         ump[dash-1]->right = ump[dash];
//                     else
//                         ump[dash-1]->left=ump[dash];
//                     dash=0;
//                 }
//             }
//         }
//         return ump[0];
//     }
// };