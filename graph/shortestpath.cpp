// problem linK:https://leetcode.com/problems/shortest-path-visiting-all-nodes/submissions/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int visNode=(1<<n)-1;
        queue<pair<int,pair<int,int>>>q; // it store nodes ,its mask and cost 
        set<pair<int,int>> s;// it tracks whether nodes is visited or not
        // Initially we store the nodes and mask in queue and visited set;
        for(int i=0;i<n;i++){
            int currmask = (1<<i);
            q.push({i,{currmask,0}});
            s.insert({i,currmask});
        }
        // Now we perform the bfs traversal 
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int node = curr.first;
            auto maskCost = curr.second;
            if(maskCost.first == visNode) return maskCost.second;
            for(auto i : graph[node]){
                int VisitedMask = maskCost.first;
                VisitedMask = VisitedMask | (1<<i);
                
                // here we are checking the state we have visited not a particular node
                // means we check if initially we are at a state where we visited 
                // if we visit 1 to 0 then 4,1 is visited in our states but not 0
                // now if we again come at 1 after visiting 0 now it is diffrent states than earlier because now we have 0 as visited,and on reaching on 1 we not visit 0 again because we have visited it already so we can return even after traversing that node because every time we mark the states of node and it may be changed depending on all nodes we have visited so we can visited a particular node more than one but doesn't fall in infinite loop .
                
                if(s.find({i,VisitedMask})==s.end()){
                    s.insert({i,VisitedMask});
                 q.push({i,{VisitedMask,maskCost.second+1}});

                }
            }
            
        }
        return -1;
    }
};
int main(){

return 0;
}