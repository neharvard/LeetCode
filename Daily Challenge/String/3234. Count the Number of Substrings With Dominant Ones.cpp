/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones
*/


/**************************************************************** C++ ****************************************************************/
//Approach -1: BruteForce (it gives TLE)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int sz = s.size();
        
        vector<int>pref(sz);
        pref[0] = s[0] - '0';
        for(int i=1; i<sz; i++) pref[i] += (s[i] - '0') + pref[i-1];

        int ans = 0;
        for(int i=0; i<sz; i++){
            int zero = 0, one = 0;
            for(int j=i; j<sz; j++){ 
              if(i > 0) one = pref[j] - pref[i-1];
              else one = pref[j];
              zero = (j-i+1) - one;
            //   cout<<"i: "<<i<<" j: "<<j<<" one: "<<one<<" zero: "<<zero<<endl;

              if(one >= (zero * zero)) ans++;
            //   else cout<<"i: "<<i<<" j: "<<j<<" one: "<<one<<" zero: "<<zero<<endl;
            }
        }
        return ans;
    }
};


//Approach-2: (Improving the brute force by skipping index j wherever possible)
//T.C : Worst case O(n^2), but since we skip indices we get O(n*sqrt(n))
//S.C : O(n)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int sz = s.size();

        vector<int>pref(sz);
        pref[0] = s[0] - '0';
        for(int i=1; i<sz; i++) pref[i] += (s[i] - '0') + pref[i-1];

        int ans = 0;
        for(int i=0; i<sz; i++){
            int oneCnt = 0, zeroCnt = 0;
            for(int j=i; j<sz; j++){
                if(i > 0) oneCnt = pref[j] - pref[i-1];
                else oneCnt = pref[j];
                zeroCnt = (j-i+1) - oneCnt;

                if(oneCnt < (zeroCnt * zeroCnt)){
                    int needed = (zeroCnt * zeroCnt) - oneCnt;
                    j += needed - 1;
                }
                else if(oneCnt == (zeroCnt * zeroCnt)) ans++;
                else{ // if(oneCnt > (zeroCnt * zeroCnt))
                    ans++;

                    int k = sqrt(oneCnt) - zeroCnt;
                    int next = j + k;

                    if(next >= sz){
                        ans += (sz - j - 1);
                        break;
                    }
                    else ans += k;

                    j = next;
                }
            }
        }
        return ans;
    }
};
