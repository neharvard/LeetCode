/*
      Company Tags                : LinkedIn
      Leetcode Link               : https://leetcode.com/problems/isomorphic-strings/
*/


/****************************************** C++ ******************************************/
//Approach-1: Using map with storing the position, not so much efficient
//T.C : O(n)
//S.C : O(1) -> as it contains ascii value of 256 size always
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sz1 = s.size();
        int sz2 = t.size();
        map<char, vector<int>>pos1, pos2;

        for(int i=0; i<sz1; i++){
            pos1[s[i]].push_back(i);
        }

        for(int i=0; i<sz2; i++){
            pos2[t[i]].push_back(i);
        }
        
        int cnt = 0;

        for(auto &it1 : pos1){
            for(auto &it2 : pos2){
                if(it1.second.size() == it2.second.size()){
                    if(pos1[it1.first] == pos2[it2.first]){
                        // cout<<"it1:"<<it1.first<<" it2:"<<it2.first<<endl;
                        cnt++;
                    }
                }
            }
        }

        if(pos1.size() == pos2.size() && pos1.size() == cnt) return true;

        return false;
    }
};



//Approach-2: Using unordered_map, more simplified
//T.C : O(n)
//S.C : O(1) -> size of map will not exceed 256

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sz = s.size();
        unordered_map<char, char>mp1, mp2;

        for(int i=0; i<sz; i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2
             || mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1){
                return false;
            }

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        
        return true;
    }
};
