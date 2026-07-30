/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/roman-to-integer/description/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (BruteForce)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int sz = s.size();

        for(int i=0; i<sz; i++){
            if(s[i] == 'I'){
                if(i<sz-1 && s[i+1] == 'V') ans += 4, i++;
                else if(i<sz-1 && s[i+1] == 'X') ans += 9, i++;
                else ans++;
            }
            else if(s[i] == 'X'){
                if(i<sz-1 && s[i+1] == 'L') ans += 40, i++;
                else if(i<sz-1 && s[i+1] == 'C') ans += 90, i++;
                else ans += 10;
            }
            else if(s[i] == 'C'){
                if(i<sz-1 && s[i+1] == 'D') ans += 400, i++;
                else if(i<sz-1 && s[i+1] == 'M') ans += 900, i++;
                else ans += 100;
            }
            else if(s[i] == 'V') ans += 5;
            else if(s[i] == 'L') ans += 50;
            else if(s[i] == 'D') ans += 500;
            else if(s[i] == 'M') ans += 1000;
        }

        return ans;
    }
};


//Approach-2 (More clean code, but use extra space)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int sz = s.size();

        unordered_map<char, int>roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        for(int i=0; i<sz; i++){
            if(i<sz-1 && roman[s[i]] < roman[s[i+1]]){
                // cout<<"i: "<<roman[s[i]]<<" i+:"<<roman[s[i+1]]<<endl;
                ans += roman[s[i+1]] - roman[s[i]];
                i++;
            }
            else ans += roman[s[i]];
        }

        return ans;
    }
};
