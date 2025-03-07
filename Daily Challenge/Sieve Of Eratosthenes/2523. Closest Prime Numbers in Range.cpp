/*
    Leetcode Link               : https://leetcode.com/problems/closest-prime-numbers-in-range
*/

//Approach-1 (Using Sieve Of Eratosthenes)
//T.C : O(NLogLogN)
//S.C : O(N)

class Solution {
public:
    #define pb push_back
    vector<int>prime;
    
    void sieve(int n){
        vector<bool> is_prime(n+1, true);
        // memset(is_prime, true, sizeof(is_prime));

        is_prime[0] = false;
        is_prime[1] = false;

        for(int i=2; i*i <= n; i++){
            if(is_prime[i] == true){
                if(i == 2){
                    for(int j=i*i; j<=n; j+=2) is_prime[j] = false;
                }
                else{
                    for(int j=i*i; j<=n; j+= (2*i)) is_prime[j] = false;
                }
            }
        }

        for(int i=2; i<=n; i++){
            if(is_prime[i]) prime.pb(i);
        }
    }
    vector<int> closestPrimes(int left, int right) {
        int n = 1e6;
        sieve(n);
        int a = -1, b = -1;

        if(right - left == 0) return {a,b};
        
        int mn = INT_MAX;
        for(int i=0; i<prime.size()-1; i++){
            if(prime[i] >= left && prime[i+1] <= right){
              int diff = (prime[i+1] - prime[i]);
              if(mn > diff){
                mn = diff;
                a = prime[i], b = prime[i+1];
              }
            }
        } 

        return {a,b};
    }
};
