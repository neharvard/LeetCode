/*
  Company Tags                : Amazon(mutiple times), Google, Uber, Facebook, Bloomberg, Yahoo, Goldman Sachs, Microsoft, Apple, Walmart Labs, 
                                Twilio, Affirm
  Leetcode Link               : https://leetcode.com/problems/group-anagrams/
  GfG Link                    : https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
*/

/************************************************************** C++ **************************************************************/
//Approach-1 (Using Sorting)
//T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz = strs.size();
        unordered_map<string, vector<int>>ump;
        
        for(int i=0; i<sz; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            // cout<<"temp:"<<temp<<endl;

            ump[temp].push_back(i);
        }
        
        int rowSz = ump.size();
        vector<vector<string>>ans(rowSz);
        
        int idx = 0;
        for(auto &it : ump){ 
            // cout<<it.first<<": ";
            for(auto &el : it.second){
                // cout<<el<<":"<<strs[el]<<" "; 
                ans[idx].push_back(strs[el]);
            } 
            idx++;
            // cout<<endl;
        }

        return ans;
    }
};



//Approach-2 (Using Sorting) Like as Approach 1 but in More Clean Code
//T.C : O(n*klog(k))  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz = strs.size();
        unordered_map<string, vector<string>>ump;
        
        for(int i=0; i<sz; i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            // cout<<"temp:"<<temp<<endl;

            ump[temp].push_back(strs[i]);
        }
        
        vector<vector<string>>ans;       
        for(auto &it : ump){ 
            ans.push_back(it.second);      
        }

        return ans;
    }
};


//Approach-2
//T.C : O(n*k)  (n = size of input, k = maximum length of a string in the input vector)
//S.C : O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz = strs.size();
        unordered_map<string, vector<string>>ump;
        vector<int>freq(26, 0);
        
        for(int i=0; i<sz; i++){
            string temp = strs[i];
            // cout<<temp<<endl;

            for(auto &el : temp){
                int x = el - 'a'; 
                freq[x]++;
            }
            
            temp = "";
            for(int i=0; i<freq.size(); i++){
                while(freq[i] > 0){
                    temp += i + 'a';
                    freq[i]--;
                } 
            }
            // cout<<"temp:"<<temp<<endl;

            ump[temp].push_back(strs[i]);
        }
        
        vector<vector<string>>ans;
        for(auto &it : ump){ 
            ans.push_back(it.second);      
        }

        return ans;
    }
};
