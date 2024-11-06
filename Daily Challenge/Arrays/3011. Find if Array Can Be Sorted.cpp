/*
    Leetcode Link               : https://leetcode.com/problems/find-if-array-can-be-sorted
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using Bubble Sort)
//T.C : O(N^2)
//S.C : O(N)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int sz = nums.size();

        vector<int>temp;
        temp = nums;
        sort(temp.begin(), temp.end());

        for(int i=0; i<sz-1; i++){
            bool swapped = false;

            for(int j=0; j<sz-i-1; j++){
                if(nums[j] > nums[j+1]){
                    string s1 = bitset<64>(nums[j]).to_string();
                    string s2 = bitset<64>(nums[j+1]).to_string();
                //   cout<<"s1:"<<s1<<" s2:"<<s2<<endl;
                    int cnt1 = 0, cnt2 = 0;
                    for(auto &el : s1){
                        if(el == '1') cnt1++;
                    }
                    for(auto &el : s2){
                        if(el == '1') cnt2++;
                    }

                    // cout<<"c1:"<<cnt1<<" c2:"<<cnt2<<endl;
                    if(cnt1 == cnt2){
                        swap(nums[j], nums[j+1]);
                        swapped = true;
                    }
                }
            }
             if(!swapped) break;
        }
        // for(auto &el : nums)cout<<el<<" ";cout<<endl;

        if(temp == nums) return true;

        return false;
    }
};


//More optimized & readable way of Approach-1 (Using Bubble Sort)
//T.C : O(N^2)
//S.C : O(1)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int sz = nums.size();

        for(int i = 0; i<sz-1; i++){
            bool swapped = false;

            for(int j = 0; j<sz-i-1; j++){
                if(nums[j] > nums[j+1]){
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])){ 
                      swap(nums[j], nums[j+1]); 
                      swapped = true;
                    }
                    else return false;
                }
            }
          
            if(!swapped) break;
        }
        return true;
    }
};


//Approach-2 (Using simple segment sorting check)
//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int sz = nums.size();

        int mn1 = INT_MAX, mn2 = INT_MAX, mx1 = INT_MIN, mx2 = INT_MIN;
        int ok = 0;
        for (int i = 0; i < sz; i++) {
            int enter = 0;
            while (i < sz - 1 && __builtin_popcount(nums[i]) == __builtin_popcount(nums[i + 1])) {
                mn1 = min({mn1, nums[i], nums[i + 1]});
                mx1 = max({mx1, nums[i], nums[i + 1]});
                i++;
                enter = 1;
            }
            
            if (!enter || i == sz - 1) {
                mn1 = min(mn1, nums[i]);
                mx1 = max(mx1, nums[i]);
            }
            // cout<<"mn1:"<<mn1<<" mx1:"<<mx1<<" mn2:"<<mn2<<" mx2:"<<mx2<<endl;

            if (ok) {
                if (mx2 > mn1) return false;
            }

            mn2 = mn1, mx2 = mx1; // previous
            ok = 1;
            mn1 = INT_MAX, mx1 = INT_MIN;
        }

        return true;
    }
};
