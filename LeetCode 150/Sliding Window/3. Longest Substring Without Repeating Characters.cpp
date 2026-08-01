/*
    Company Tags  : Bloomberg, Facebook, Google, Amazon, Adobe
    Leetcode Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

//Approach-1 (my initial approach, code is messy)
// TC: O(N)
// SC: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        set<char>st;
        int ans = 0;

        for(int i=0,j=0; i<sz; i++){
            if(st.find(s[i]) != st.end()){
                int len = st.size();
                ans = max(ans, len);
                // cout<<"len:"<<len<<" ans:"<<ans<<" s[i]:"<<s[i]<<endl;

                // cout<<"before"<<endl;for(auto &it : st) cout<<it<<" "; cout<<endl;

                auto it = *st.begin(); 
                while(s[j] != s[i]){
                    // cout<<"i:"<<s[i]<<" j:"<<s[j]<<endl;
                    st.erase(s[j]);
                    j++;
                }
                j++;
                st.insert(s[i]);

                // cout<<"after"<<endl; for(auto &it : st) cout<<it<<" "; cout<<endl;

            }
            else st.insert(s[i]);
        }
        
        // for(auto &it : st) cout<<it<<" "; cout<<endl;
        int len = st.size(); 
        ans = max(ans, len);

        return ans;
    }
};


//Approach-2 (same concept as approach-1, More Clean Code)
// TC: O(N)
// SC: O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        set<char>st;
        int ans = 0;

        for(int i=0,j=0; j<sz; j++){
            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};

