/*
	Company Tags			: Amazon, MakeMyTrip, Microsoft
	Leetcode Link 			: https://leetcode.com/problems/word-pattern/
*/

//Approach-1 : (using map) Use two hash maps to ensure a bijective mapping between pattern characters and words
// TC : O(n+m)
// SC : O(26) = O(1)

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int sz1 = pattern.size();
        int sz2 = s.size();
      
        unordered_map<char, string>mp1;
        unordered_map<string, char>mp2;
        string temp;
        int word = 0;

        for(int i=0, j=0; i<sz2; i++){
            if(s[i] == ' ' || i == sz2-1){
                if(i == sz2-1) temp += s[i];
                // cout<<"temp:"<<temp<<" pt:"<<pattern[j]<<endl;

                if(mp1.find(pattern[j]) != mp1.end() && mp1[pattern[j]] != temp
                || mp2.find(temp) != mp2.end() && mp2[temp] != pattern[j])
                {
                    return false;
                }

                mp1[pattern[j]] = temp;
                mp2[temp] = pattern[j];

                temp.erase();
                j++;
                word++;
            }
            else temp += s[i];
        }

        if(word != sz1) return false;

        return true;
    }
};
