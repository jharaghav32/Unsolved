#include<bits/stdc++.h>
using namespace std;
/*
Problem Link :https://leetcode.com/problems/3sum-closest/
**EXPLANATION**
here we have to find sum of 3 numbers which is closed to given target 
what we do is first sort the array  
and then run a loop from i=0 to n 
inside it take two pointer one pointing next to i and other pointing the last element
every time find the sum if it is equal to target return sum
and also store the sum by comparing it with target
if our sum is less than target we have to increase the sum so we increase the second pointer
and if we need to decrease the sum we decrease the third pointer which is initially
pointing to last element as array is sorted on decreasing the third pointer element become
less than earlier element 
In this way after taking all elements we return ans ;
*/
/*CODE*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans =nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target)return sum;
              else  if(sum<target)j++;
                else k--;
             if(abs(target-ans)>abs(target-sum))
                 ans=sum;
            }
        
        }
        return ans;
    }
};