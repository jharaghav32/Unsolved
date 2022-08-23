//problem link:https://leetcode.com/problems/validate-binary-tree-nodes/submissions/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //for a binary tree we calculate the indegree of every nodes if any node has indegree more than 1 return false other case be there is two different tree so to  chck
    //if moret than 1 nodes have 0 indegree it means there are more than one root
    // then we return false
    // after that we call a dfs from root node and count the no of nodes if no of nodes
    // is equal to n then return true else return false
    int dfs(int root,vector<int>&leftChild,vector<int>&rightChild){
        if(root==-1)return 0;
        return 1 + dfs(leftChild[root],leftChild,rightChild)+dfs(rightChild[root],leftChild,rightChild);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>indeg(n);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1 && ++indeg[leftChild[i]]>1)
                return false;
            if(rightChild[i]!=-1 && ++indeg[rightChild[i]]>1)
                return false;
            
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(indeg[i]==0 ){
                if(root==-1){
                root=i;
                }
                else
                return false;
            }
        }
        
        if(dfs(root,leftChild,rightChild)==n)return true;
        return false;
    }
};