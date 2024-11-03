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
