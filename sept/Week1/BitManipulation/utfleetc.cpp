#include<bits/stdc++.h>
using namespace std;

// Problem Link : https://leetcode.com/problems/utf-8-validation/

// to get most significant bit we can use rightshift operator
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int rem=0;
        // here 0b110 means a  binary number starting with 0 end with 110 and in betweeen there can be 0 or 1 any thing pssble
        for(int i=0;i<n;i++){
            int elem = data[i]&255; //to get least significant 8 bits
            if(!rem){
                if(elem>>5==0b110)rem=1;// to get 2 byte
                else if(elem>>4==0b1110)rem=2; // to get 3 byte
                else if(elem>>3==0b11110)rem=3;// to get 4 byte
                else if(elem>>7)return false;// now if apart then any number exist
                // with starting 1 we directly return false because we have already checked for 2,3 and 4 byte and no ohter byte existed 
            }
            else{
                if(elem>>6!=0b10)return false;
                rem--;
            }
                
        }
        if(rem==0)return true;
        return false;
    }
};