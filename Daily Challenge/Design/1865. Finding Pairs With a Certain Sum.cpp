/*
    Leetcode Link               : https://leetcode.com/problems/finding-pairs-with-a-certain-sum
*/


/***************************************************************** C++ *****************************************************************/
//Approach (Using map and approach similar to Two Sum Problem)
//T.C : O(m+n) for FindSumPairs(), O(1) for add() and O(n) for count()
//S.C : O(m+n) for vec1 and vec2
class FindSumPairs {
public:
    vector<int>v1,v2;
    unordered_map<int,int>freq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
        for(auto &it : v2) freq[it]++;
    }
    
    void add(int index, int val) {
        if(freq[v2[index]] > 0) freq[v2[index]]--;
        v2[index] += val;
        freq[v2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;

        for(int &num : v1){
            ans += freq[tot - num];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
