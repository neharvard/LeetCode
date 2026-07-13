/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/h-index/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Array/Counting, using vector container of len(1000) to store the value)
// TC: O(n * c)
// SC: O(1000)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();
        vector<int>v(10001);

        for(int i=0; i<sz; i++){
            for(int j=1; j<=citations[i]; j++){
                v[j]++;
            }
        }

        // for(auto &it : v)cout<<it<<" "; cout<<endl;

        int ans = 0;
        for(int i=1000; i>0; i--){
            if(v[i] >= i) return i;
        }

        return ans;
    }
};



//Approach-2 (More Efficient, on the fly find the value)
// TC: O(nlogn)
// SC: O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int sz = citations.size();

        sort(begin(citations), end(citations));

        for(int i=0; i<sz; i++){
            int rem = sz - i;
            if(citations[i] >= rem) return rem;
        }
       
        return 0;
    }
};
