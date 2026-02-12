/*
    	Company Tags  		          : 
    	Leetcode Link 		          : https://leetcode.com/problems/longest-balanced-substring-i
*/


/*************************************************************** C++ *************************************************/
//Approach-1: (try all subarrays)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int longestBalanced(string s) {
        int sz = s.size(), ans = INT_MIN;

        for(int i=0; i<sz; i++){
            unordered_map<char,int>freq;
           
            for(int j=i; j<sz; j++){
                freq[s[j]]++; 
                int ok = -1, flg = 0; ///cout<<"temp: "<<temp<<endl;
                for(auto &it : freq){ ///cout<<"f:"<<it.first<<" s:"<<it.second<<endl;
                    if(ok == -1) ok = it.second;
                    else{
                        if(ok != it.second){
                            flg = 1;
                            break;
                        }
                    }
                } 
                if(flg) continue;
                else{
                    int n = freq.size(); 
                    ans = max(ans, n*ok); //cout<<"n: "<<n<<" ans:"<<ans<<endl;
                }
            }
        }

        return ans;
    }
};



//Approach-2: (try all subarrays) More Cleaner Code
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool isBalance(vector<int>& freq){
        int limit = 0;
        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;
            if(limit == 0) limit = freq[i];
            else if(freq[i] != limit) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int sz = s.size(), ans = INT_MIN;

        for(int i=0; i<sz; i++){
            vector<int>freq(26,0);
           
            for(int j=i; j<sz; j++){
                freq[s[j] - 'a']++; 
                if(isBalance(freq)) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};
