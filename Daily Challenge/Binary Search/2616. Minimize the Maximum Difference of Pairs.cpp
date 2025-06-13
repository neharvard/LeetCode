/*
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
      Similar Qn                  : https://www.youtube.com/watch?v=lWU1wI7koGk
*/


/************************************************************************ C++ ******************************************************************/
//Binary Search + Greedy (This is the same Qn of pattern "Applying binary search on answer" (Time Compplexity - O(m * log(n)) where m = max diff in pair
//How to identify -> Notice the keywords - "min max"
/*
    Whenever we see in Question to Find Min(Max) or Max(Min) 
    we will try to use Binary search on the result
*/
//T.C : O(nlogn)
//S.c : O(1)
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0, low = 0, high = nums[sz-1] - nums[0];

        while(low <= high){
            int mid = low + (high - low)/2;
            cout<<"low:"<<low<<" high:"<<high<<" mid:"<<mid<<endl;

            int cnt = 0, i = 0;
            while(i<sz-1 && cnt <= p){
                if(nums[i+1] - nums[i] <= mid){
                    cnt++; i+=2;
                }
                else i++;
            }

            if(cnt >= p){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};
