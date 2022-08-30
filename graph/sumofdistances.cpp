#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // here using the below dfs function dfs function we want to find the sum of distance of child node from parent node after making every node as parent of tree
    // where count[nodes] keeps an account of total nodes of subtree or tree where 
    // nodes is the root of tree.
   void dfs(int node,int parent,vector<int>adj[],vector<int>&count,vector<int>&res){
       for(auto i: adj[node]){
           if(i==parent)continue;
           dfs(i,node,adj,count,res);
           count[node]+= count[i]; // adding the count of child to parent
           res[node]+= res[i] + count[i]; // and sum of distance of subtree is 
           // sum of distances from its child + count of child
       }
       count[node]+=1;// here after traversing all the child of parent we increment the
       // count by adding the node itself
   }
    //this dfs function actually find the sum of distances to every node 
    //actually if we have ans for parent node and we move to child node then there are 
    // some nodes to which we got closer and we move away from some nodes
    //actually the closer nodes are the nodes to which we moved and its child 
    //and we have count[nodes] which calculate the nodes and its child so it means that
    // we move count[nodes] closer and totalnodes-count[nodes] away so as parent to 
    // child distance is 1 we add the no of away nodes and the subtract the close nodes
    // from parent result and this is our answer for nodes
    // we use this technique to find result for every node
    void dfs1(int node,int parent,vector<int>adj[],vector<int>&count,vector<int>&res,int n){
        for(auto i : adj[node]){
            if(i==parent)continue;
            res[i]=res[node]-count[i] + n-count[i];
            dfs1(i,node,adj,count,res,n);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
         adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>count(n,0);
        vector<int>res(n,0);
        dfs(0,-1,adj,count,res);
        dfs1(0,-1,adj,count,res,n);
    return res;
    }
};
int main(){

return 0;
}