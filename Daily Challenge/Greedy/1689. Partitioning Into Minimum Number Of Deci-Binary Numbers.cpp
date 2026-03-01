/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/



/**************************************************************** C++ ********************************************************************/
//Approach-1 (The largest character will take time to reach 0)
//T.C : o(n)
//S.C : O(1)
class Solution {
public:
    int minPartitions(string n) {
        int ans = -1;

        for(auto &it : n){
            int x = it - '0'; //cout<<"It: "<<it<<endl;
            ans = max(ans, x);
        }

        return ans;
    }
};
