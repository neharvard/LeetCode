/*
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (BruteForce, using map)
//T.C : O(N^2)
//S.C : O(1)
class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for (auto& it : s) freq[it]++;

        int ans = INT_MIN;
        for (auto it : freq) {
            int freq_it = it.second;
            // cout << "it:" << it.first << " " << freq_it << endl;

            for (auto el : freq) {
                if (el.first == it.first) continue;
                // cout << "el:" << el.first << " " << el.second << endl;

                if (el.second % 2 != 0 && freq_it % 2 == 0)
                    ans = max(ans, (el.second - freq_it));
                else if (freq_it % 2 != 0 && el.second % 2 == 0)
                    ans = max(ans, (freq_it - el.second));
            }
        }

        return ans;
    }
};


//Approach-2 (Straught forward maxOdd - minEven)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxDifference(string s) {
        vector<int>freq(26, 0);
        for(char &ch : s){
            freq[ch - 'a']++;
        }

        int mxOdd = INT_MIN;
        int mnEven = INT_MAX;
      
        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;

            if(freq[i]%2) mxOdd = max(mxOdd, freq[i]);
            else mnEven = min(mnEven, freq[i]);
        }

        int ans = mxOdd - mnEven;
        return ans;
    }
};
