#include<bits/stdc++.h>
using namespace std;

// problem link :https://leetcode.com/problems/my-calendar-iii/submissions/

/* 
**EXPLANATION** 
eg- [10,20][50,60][10,40][5,15][5,10][25,55]
mp[10]++;increment the start interval
mp[20]--;decrement the end interval
10---1
20---(-1)
add cnt to 1 means there is one interval and when we reaches 20 it adds to zero as 1+(-1)
means that one interval ends so in between if there is any interval we simply count it
and when it ends we remove it by subtracting -1
in this way after every operation we take max and return max of it that define 
the max common interval 

*/




class MyCalendarThree {
public:
    //Here we increment the start interval and then decrement
    // the end interval as map is initialised with zero  whenever any interval
    // start we increment it to 1 and when it ends we decrement to -1 then we simply
    // add the value at particular interval and take max of it whenever interval ends 
    //value becomes 1-1=0 it means now that interval is not in count
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int ans=INT_MIN;
        int cnt=0;
        for(auto i:mp){
            cnt+=i.second;
            ans =max(ans,cnt);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
int main(){

return 0;
}