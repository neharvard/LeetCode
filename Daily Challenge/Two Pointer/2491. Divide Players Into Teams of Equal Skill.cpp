/*
    Leetcode Link               : https://leetcode.com/problems/divide-players-into-teams-of-equal-skill
*/


/************************************************************ C++ ************************************************/
// Approach: Using 2 Pointer
//T.C : O(N Log N) , S.C : O(1)
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sz = skill.size();
        sort(skill.begin(), skill.end());

        long long ans = 0;
        int sum = 0, temp = 0, ok = 0;
        for(int i=0,j=sz-1; i<j; i++,j--){
            sum = skill[i] + skill[j]; 
            // cout<<"t:"<<temp<<" sum:"<<sum<<endl;
            if(temp == 0){
                ans += (skill[i] * skill[j]);
                temp = sum;
            }
            else if(temp == sum){
                ans += (skill[i] * skill[j]);
                temp = sum;
            } else{
                ok = 1; break;
            }
        }

        if(ok) return -1;
        return ans;
    }
};
