/*
    Leetcode Link                              : https://leetcode.com/problems/sum-of-k-mirror-numbers/
    
*/

/****************************************************** C++ **************************************************************/
//Approach-0: Brute Force, TLE
//T.C : ~O((10 ^ D) * D), where D = number of digits in k-mirror number
//S.C : O(D), where D = number of digits in k-mirror number
class Solution {
public:
#define ll long long int
    long long kMirror(int k, int n) {

        /// BruteForce, TLE
        int cnt = 1;
        long long int num = 2, ans = 1;

        while(cnt < n){
            long long int temp = num;
            string s = to_string(temp);
            string rev = s;
            reverse(rev.begin(), rev.end());
            cout<<"s: "<<s<<" rev: "<<rev<<endl;
            if(s == rev){
                s = ""; rev = "";
                while(temp){
                    int rem = temp % k;
                    s += to_string(rem);
                    temp /= k;
                }
                rev = s;
                reverse(rev.begin(), rev.end());
                cout<<"s1: "<<s<<" rev1: "<<rev<<endl;

                if(s == rev){
                    ans += num;
                    cnt++;
                }
            }
            num++;
        }
        return ans;
    }
};


//Approach-1: Using palindrome generation logic
//T.C : ~O((10 ^ D) * D), where D = number of digits in k-mirror number
//S.C : O(D), where D = number of digits in k-mirror number
class Solution {
public:
#define ll long long int
    
    string convertToBaseK(ll num, int k){
        if(num == 0) return "0";

        string res = "";
        while(num){
            res += to_string(num%k);
            num /= k;
        }
        return res;
    }

    long long kMirror(int k, int n) {
        ll ans = 0;
        ll len = 1;

        while (n > 0) {
            ll half_len = (len + 1) / 2;  // (1+1)/2 = 1

            ll mn_num = pow(10, half_len - 1); // 10^0 = 1
            ll mx_num = pow(10, half_len) - 1; // 10^1-1 = 9

            // generate all the Palindrome of length wise
            for (ll num = mn_num; num <= mx_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(second_half.begin(), second_half.end());

                string pal = "";
                if (len % 2) { // odd len
                    pal = first_half + second_half.substr(1);
                } else pal = first_half + second_half;
                
                ll pal_num = stoll(pal);
                // cout<<"pal_string: "<<pal<<" pal_num: "<<pal_num<<endl;

                string baseK = convertToBaseK(pal_num, k);
                
                string rev = baseK;
                reverse(rev.begin(), rev.end());
                
                if(baseK == rev){ 
                // cout<<"pal: "<<pal_num<<" base: "<<baseK<<" rev: "<<rev<<endl;
                    ans += pal_num;
                    n--;
                    
                    if(n == 0) return ans;
                }
            }

            len++;
        }

        return ans;
    }
};
