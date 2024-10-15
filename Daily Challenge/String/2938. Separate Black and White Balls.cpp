/*
    Leetcode Link               : https://leetcode.com/problems/separate-black-and-white-balls
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (2 Pointer)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        for(int i=0,j=1; i<s.size(); i++){
            if(s[i] == '1'){ 
                if(j <= i) j = i+1;
                while(j<s.size() && s[j] == '1'){
                  j++;
                }            
                if(j == s.size()) break;
                swap(s[i],s[j]);
                ans += (j-i); 
             //cout<<"jjj:"<<j<<" "<<s[j]<<" ans:"<<ans<<endl;
            }
        }
        return ans;
    }
};


//Approach-2 (straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int black = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') ans += black;
            else black++;
        }
        return ans;
    }
};


//Approach-2 (Reversed traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int white = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == '1') ans += white;
            else white++;
        }
        return ans;
    }
};
