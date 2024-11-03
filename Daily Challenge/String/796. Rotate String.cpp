/*
    Leetcode Link               : https://leetcode.com/problems/rotate-string
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force)
//T.C : O(N)
//S.C : O(N)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int sz = s.size();
        int ok = 0, idx;

        if(sz != goal.size()) return false;

        for(int i=0; i<sz; i++){
            if(s[i] == goal[0]){
                string s1 = s.substr(i, sz-i);
                string g1 = goal.substr(0, sz-i);

                if(s1 == g1){
                    ok = 1, idx = i;
                    break;
                }
            }
        }

        if(!ok) return false;  //cout<<"id:"<<idx<<endl;

        for(int i=0, j=(goal.size()-idx); i<idx; i++, j++){ 
            if(s[i] != goal[j]) return false;
        }

        return true;
    }
};


//Approach-2 (Brute Force Check all rotations)
//T.C : O(N^2)
//S.C : O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int sz = s.size();
        
        for(int i=0; i<sz; i++){
            rotate(s.begin(), s.begin()+1 ,s.end());
            cout<<"ss:"<<s<<endl;
            if(s == goal) return true;
        }
        return false;
    }
};


//Approach-3 (Concatenation with itself contains all possible rotations)
//T.C : O(N)
//S.C : O(1)
// NOTE :         If concatenate a String with itself, it will contain all Rotations as a Substring in it
class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()) return false;

        if((s+s).find(goal) != string::npos) return true;

        return false;
    }
};
