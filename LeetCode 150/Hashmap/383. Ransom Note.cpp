/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/ransom-note
*/

//Approach-1: using Hashmap [not soo efficinet]
// TC : O(n)
// SC: O(n)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>ran,mag;

        for(auto &it : ransomNote) ran[it]++;
        for(auto &it : magazine){
            if(ran.find(it) != ran.end()) mag[it]++;
        } 

        // for(auto &it : ran) cout<<it.first<<" "<<it.second<<" "; cout<<endl;
        // for(auto &it : mag) cout<<it.first<<" "<<it.second<<" "; cout<<endl;
        
        if(ran.size() != mag.size()) return false;

        for(auto &it : mag){
            // cout<<it.first<<" "<<it.second<<" "<<ran[it.first]<<endl;

            if(ran[it.first] > it.second) return false;
        }

        return true;
    }
};



//Approach-2: using static storage
// TC : O(n)
// SC: O(26) = O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>v(26, 0);
        for(auto &it : magazine){
            int x = it - 'a'; 
            // cout<<"x: "<<x<<endl;
            v[x]++;
        }

        for(auto &it : ransomNote){
            int num = it - 'a';
            if(v[num] == 0) return false;

            v[num]--;
        }

        return true;
    }
};
