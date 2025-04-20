/*
    Leetcode Link               : https://leetcode.com/problems/rabbits-in-forest/description
*/


/************************************************************ C++ *****************************************************/
//Approach (Grouping using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        int ans = 0;

        for(auto &it : answers) freq[it]++;
        for(auto &it : freq){
            int x = it.first;
            int count = it.second;

            int groupSize = (x+1);
            int groups = ceil((double)count/groupSize);

            ans += (groups * groupSize);
        } 

        return ans;
    }
};
