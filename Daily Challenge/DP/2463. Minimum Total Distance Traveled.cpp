/*
    Leetcode Link               : https://leetcode.com/problems/minimum-total-distance-traveled
*/


//Approach: (Using Recursion + Memoization)
// TC : O(M * N)
// SC : O(M * N)
class Solution {
public:
    #define Max 10000000000000LL
    #define ll long long

    long long solve(vector<int>& robot, int robot_pos, vector<int>& factories, int fact_pos, vector<vector<ll>>& memo){
        if(robot_pos < 0) return 0; // if there is no robot left
        if(fact_pos < 0) return Max; // if there is robot left but factory limit over

        if(memo[robot_pos][fact_pos] != -1){
            return memo[robot_pos][fact_pos];
        }


        ll include = abs(robot[robot_pos] - factories[fact_pos]) 
                      + solve(robot, robot_pos-1, factories, fact_pos-1, memo);
        
        ll exclude = solve(robot, robot_pos, factories, fact_pos-1, memo);

        return memo[robot_pos][fact_pos] = min(include, exclude);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
       sort(robot.begin(), robot.end());
       sort(factory.begin(), factory.end());
       
       int n = robot.size();
       int m = factory.size();
       vector<int>factories;

       for(int i=0; i<m; i++){
         int pos = factory[i][0];
         int cnt = factory[i][1];
         for(int j=0; j<cnt; j++) factories.push_back(pos);
       }

       vector< vector<ll >>memo(n, vector<ll>(factories.size(), -1));

       return solve(robot, n-1, factories, factories.size()-1, memo);
    }
};

// DP, TC: O(MN), SC: O(MN)
