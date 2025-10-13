/*
    Leetcode Link               : https://leetcode.com/problems/find-resultant-array-after-removing-anagrams
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using set and substring find)
//T.C : O(N∗Klogk)
//S.C : O(N)
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        int sz = words.size();

        for(int i=1; i<sz; i++){
            ans.push_back(words[i-1]);

            string temp1 = words[i-1];
            string temp2 = words[i];
            sort(begin(temp1), end(temp1));
            sort(begin(temp2), end(temp2));
            // cout<<"t1:"<<temp1<<" t2: "<<temp2<<endl;

            while(i<sz-1 && temp1 == temp2){
                i++;
                temp2 = words[i];
                sort(begin(temp2), end(temp2)); 
                // cout<<"t222: "<<temp2<<endl;
            }
        }
        string temp1 = words[sz-1];
        sort(begin(temp1), end(temp1));
        
        if(sz > 1){
            string temp2 = words[sz-2];
            sort(begin(temp2), end(temp2));
            if(temp1 != temp2)ans.push_back(words[sz-1]);
        }
        else ans.push_back(words[sz-1]);

        return ans;
    }
};
