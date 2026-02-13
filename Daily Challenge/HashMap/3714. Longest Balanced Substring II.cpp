/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/longest-balanced-substring-ii/
*/


/************************************************************ C++ *****************************************************/
//Approach (storing diff in Map)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int sz;
    int solve(string& s, char ch1, char ch2){
        int cnt1 = 0, cnt2 = 0, ans = INT_MIN;
        unordered_map<int,int>diffMap;

        for(int i=0; i<sz; i++){
            if(s[i] != ch1 && s[i] != ch2){
                diffMap.clear();
                cnt1 = 0, cnt2 = 0;
                continue;
            }

            if(s[i] == ch1) cnt1++;
            else if(s[i] == ch2) cnt2++;
            int diff = cnt1 - cnt2; 
            // cout<<"c1:"<<cnt1<<" c2: "<<cnt2<<" diff: "<<diff<<endl;

            if(cnt1 == cnt2) ans = max(ans, cnt1+cnt2);
            else if(diffMap.count(diff)) ans = max(ans, i - diffMap[diff]);
            else diffMap[diff] = i;
           
        }
        return ans;
    }
    int longestBalanced(string s) {
        sz = s.size();
        int ans = INT_MIN;

        // Case-1: depend upon one char
        int cnt = 1;
        for(int i=1; i<sz; i++){
            if(s[i] == s[i-1]) cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt); //cout<<"a1: "<<ans<<endl;

        // Case-2: depend upon two char
        ans = max(ans, solve(s, 'a', 'b')); //cout<<"a2: "<<ans<<endl;
        ans = max(ans, solve(s, 'a', 'c')); //cout<<"a3: "<<ans<<endl;
        ans = max(ans, solve(s, 'b', 'c')); //cout<<"a4: "<<ans<<endl;

        // Case-3: depend upon three char
        unordered_map<string, int>diffMap;
        int cntA = 0, cntB = 0, cntC = 0;

        for(int i=0; i<sz; i++){
            if(s[i] == 'a') cntA++;
            else if(s[i] == 'b') cntB++;
            else if(s[i] == 'c') cntC++;

            int diffAB = cntA - cntB;
            int diffAC = cntA - cntC; 
            string key = to_string(diffAB) + '_' + to_string(diffAC); 
            // cout<<"c1: "<<diffAB<<" c2: "<<diffAC<<" key: "<<key<<endl;

            if(cntA == cntB && cntA == cntC) ans = max(ans, cntA+cntB+cntC);       
            else if(diffMap.count(key)) ans = max(ans, i - diffMap[key]); 
            else diffMap[key] = i;
        }

        return ans;

    }
};
