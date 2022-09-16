// Problem Link : https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/submissions/

#include<bits/stdc++.h>
using namespace std;
// IN this problem first approach is we think of is greedy but greedy fails because if we  optimally take max element 
// from start or end may be the element on multiplier side is minimum and it will not give us a max product as we
// can we use that max element for another greater element in multipliers array
// so whenever greedy approach fails thinks of recursion
// In recursion think of all pssble cases 
// The cases are we can take element from first or start this is the case so recursively we call the fun and one time 
// we take element from start and in another case we take element from end 
// after we do recursion try to change it into dp and as we recursively code it our maximum job is done
// Now for dp see which param in recursive function is changing  here there are three params that are changing 
// one is left index and other one is right index of nums array and third one is index of multipliers array
// as left index and right index of array are interdependent so we take any of left,right and index of multipliers
// array we create a 2d dp array of size of multipliers array  and then initialise the value with minimum integer value
// and memoise it 
// ThankYou your job is done 
class Solution {
public:
    int dp[1000][1000];
    int maximum(vector<int>&nums,vector<int>&multipliers,int i,int j,int m,int idx){
        if(idx>=m )return 0;
        if(dp[idx][i]!=INT_MIN)return dp[idx][i];
        int start = maximum(nums,multipliers,i+1,j,m,idx+1)+(multipliers[idx]*nums[i]);
                int end = maximum(nums,multipliers,i,j-1,m,idx+1)+(multipliers[idx]*nums[j]);
        return dp[idx][i]=max(start,end);

    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        for(int i=0;i<1000;i++){
            for(int j=0;j<1000;j++){
                dp[i][j]=INT_MIN;
            }
        }
     int n = nums.size();
        int m = multipliers.size();
        return maximum(nums,multipliers,0,n-1,m,0);
    }
};