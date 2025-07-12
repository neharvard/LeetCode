/*
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/description/
*/

/************************************************************ C++ ************************************************************/
//Approach-1: (Using Bitmak & Two Pointer)
//T.C : O(2^n), 
//S.C : O(2^n)
class Solution {
public:
    int mn = INT_MAX, mx = INT_MIN;
    int sz = 0 , first = 0, second = 0;

    void solve(int mask, int round, int i, int j){
        if(i >= j){
            solve(mask, round+1, 0, sz); // round is completed
        }
        else if((mask & (1<<i)) == 0){ 
            // ith bit is 0 means that player is dead, ith pointer move 
            solve(mask, round, i+1, j);
        }
        else if((mask & (1<<j)) == 0){
            // jth bit is 0 means that player is dead, jth pointer move
            solve(mask, round, i, j-1);
        }
        else if(i == first && j == second){ 
            // calculate the round mn, mx
            mx = max(mx, round);
            mn = min(mn, round);
        }
        else if(i == first || i == second){
            // jth bit need to 0 mean jth player have to dead,
            solve((mask ^ (1<<j)), round, i+1, j-1);
        }
        else if(j == first || j == second){
            // ith bit need to 0 mean ith player have to dead,
            solve((mask ^ (1<<i)), round, i+1, j-1);
        }    
        else{
            // anyone can dead
            solve((mask ^ (1<<i)), round, i+1, j-1);
            solve((mask ^ (1<<j)), round, i+1, j-1);
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        sz = n-1, first = firstPlayer - 1, second = secondPlayer - 1;
        int round = 1, i = 0, j = n-1;

        solve((1<<n)-1, round, i, j);

        return {mn, mx};
    }
};
