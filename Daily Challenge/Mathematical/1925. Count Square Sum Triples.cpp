/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/count-square-sum-triples/description/
*/



/****************************************************************** C++ ******************************************************************/
//Approach - 1: BruteForce
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        if(n <= 3) return ans;

        for(int i=4; i<=n; i++){
            for(int j=1; j<i; j++){
                for(int k=1; k<j; k++){
                    // cout<<"i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
                    int x = (j*j) + (k*k);
                    int y = (i*i);
                    // cout<<"x: "<<x<<" y: "<<y<<endl;

                    if(x == y) ans += 2;
                }
            }
        }

        return ans;
    }
};



//Approach - 2: Applying the formula 
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                int sum = (i*i) + (j*j);
                int x = sqrt(sum);

                if((x*x) == sum && x <= n) ans += 2;
            }
        }

        return ans;
    }
};
