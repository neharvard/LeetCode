/*
    Leetcode Link               : https://leetcode.com/problems/prime-subtraction-operation
*/


/************************************************************ C++ ************************************************/
//Approach (Store prime and check)
//T.C : O(N * maxNum)
//S.C : O(1000) ~ O(1)
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int>prime;

        for(int i=2; i<=1000; i++){
            int ok = 0;
            for(int j=2; j*j <= i; j++){
                if(i % j == 0){ 
                    ok = 1; break;
                }
            }
            if(!ok) prime.push_back(i);
        }

        // for(auto &el: prime)cout<<el<<" ";cout<<endl;

        for(int i = nums.size()-1; i>0; i--){
            if(nums[i] <= nums[i-1]){
                int sub = 0; 

                for(int j=0; j<prime.size(); j++){

                    if(prime[j] >= nums[i-1]) break;
                    if((nums[i-1] - prime[j]) < nums[i]){
                        sub = prime[j]; 
                        break;
                    }
                }

                nums[i-1] -= sub;
                if(nums[i] <= nums[i-1]) return false;
            }
        }

        // for(auto &el : nums)cout<<el<<" ";cout<<endl;

        return true;
    }
};



//Approach (Store prime and check) [ Using Seive Eratosthenes, More Optimized Approach ] 
//T.C : O(N * maxNum)
//S.C : O(1000) ~ O(1)
class Solution {
public:
    bool isPrime[1001];
    void seive() {
        memset(isPrime, true, 1001);
        isPrime[0] = false, isPrime[1] = false;

        for (int i = 2; i * i <= 1000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 1000; j += i )
                    isPrime[j] = false;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {

        seive();
        // for(int i = 0; i < 1000; i++)if(isPrime[i])cout<<i<<" ";
        
        for(int i = nums.size()-1; i>0; i--){
            if(nums[i] <= nums[i-1]){

                for(int j = 2; j<nums[i-1]; j++){
                    if(isPrime[j]){
                        if((nums[i-1] - j) < nums[i]){
                            nums[i-1] -= j; break;
                        }                          
                    }
                }
            }

            if(nums[i] <= nums[i-1]) return false;
        }
        // for(auto &el : nums)cout<<el<<" ";cout<<endl;

        return true;
    }
};
