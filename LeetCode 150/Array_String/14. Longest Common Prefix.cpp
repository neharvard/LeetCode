class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size();
        unordered_map<string, int>freq;

        for(int i=0; i<sz; i++){
            string temp;
            for(auto &it : strs[i]){
                temp += it;
                freq[temp]++;
            }
        }
        
        string ans;
        int temp = 0;
        for(auto &it : freq){
            if(it.second >= sz && it.first.size() > temp){
                ans = it.first;
                temp = it.first.size();
            }
        }

        return ans;
    }
};
