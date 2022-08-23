// problem link:https://leetcode.com/problems/shortest-path-with-alternating-colors/submissions/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Here as we know that to find the shortest path we use bfs technique
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // we store the adjacency matrix with destination node and its edge color
        // consider red as 0 and blue as 1
        // we initially assign the color of node 0 is -1 so that from 0 we can go to any
        // colored edges
        vector<pair<int,int>>adj[n];
        for(int i=0;i<redEdges.size();i++){
            adj[redEdges[i][0]].push_back({redEdges[i][1],0});
        }
for(int i=0;i<blueEdges.size();i++){
            adj[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }        
        // Now here we create a vector which store the node value ,its distance from
        // source node and the color 
    queue<vector<int>>q;
        q.push({0,0,-1});// initialy push 0 node ,0 distance, and for color -1
        vector<int>dist(n,-1);// created a distance which store the path distance
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            // if the node is not visited then store the distance from the queue
            if(dist[curr[0]]==-1){
                dist[curr[0]]=curr[1];
            }
            // now traverse the edge of node
            
          for(auto &i:adj[curr[0]]){
              if(i.second!=curr[2] && i.first!=-1){
                  // if edge color is different and we have not visited tha path
                  // then we push the node, distance and color
                  q.push({i.first,curr[1]+1,i.second});
                  i.first=-1;// here we made the node to -1 so that we need not 
                  // to visit the same path again and again 
                  //for example if  from 0 there is {1,0} and {1,1} 
                  // if we traversed {1,0} then change it to {-1,0} so that we need
                  // not to visit that one again
              }
          }
        }
        
        return dist;
        
        
    }
};