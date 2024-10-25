/*
    Leetcode Link               : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using set and substring find)
//T.C : O(N ∗ M ∗ Logn)
//S.C : O(N)
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string>st;
        sort(folder.begin(), folder.end());

        vector<string>ans;
        for(auto &it : folder){
            string temp;
            int ok = 0;
            for(auto &el : it){
                if(el == '/'){
                    if(st.find(temp) != st.end()){ //cout<<"t1:"<<temp<<endl;
                        ok = 1; break;
                    }
                }
                temp += el;
            } // cout<<"ok:"<<ok<<" t:"<<temp<<endl;
            if(!ok){
                st.insert(it); ans.push_back(it);
            } 
        }

        return ans;
    }
};
