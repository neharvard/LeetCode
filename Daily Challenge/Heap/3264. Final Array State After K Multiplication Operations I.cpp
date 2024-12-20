/*
    Leetcode Link               : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Brute Force)
//T.C : O(n * k)
//S.C : O(1)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        for (int j = 0; j < k; j++) {

            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[idx]) {
                    idx = i;
                }
            }

            nums[idx] *= multiplier;
        }

        return nums;
    }
};


//Approach-2 (Using stl::priority_queue)
//T.C : O(nlogn + klogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int,int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       int n = nums.size();
       priority_queue<P, vector<P>, greater<P> > pq;

       for(int i=0;i<n;i++) pq.push({nums[i],i});

       while(!pq.empty() && k--){
         int el = pq.top().first * multiplier;
         int idx = pq.top().second;
         pq.pop();
         //  cout<<pq.top().first<<" "<<pq.top().second; pq.pop(); cout<<endl;
         pq.push({el, idx});
       }

       vector<int>ans(n);
       while(!pq.empty() ){
         ans[pq.top().second] = pq.top().first;
         pq.pop(); 
       }

       return ans;
    }
};



//Approach-3 (Using vector as heap for O(n) heapify)
//T.C : O(n + klogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int,int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       int n = nums.size();
       vector<P>vec;

       for(int i=0;i<n;i++) vec.push_back({nums[i],i});

       make_heap(vec.begin(), vec.end(), greater<>());

       while(k--){
         pop_heap(vec.begin(), vec.end(), greater<>());
         P temp = vec.back();
         vec.pop_back();

         int el = temp.first;
         int idx = temp.second;
         nums[idx] = el * multiplier;

         vec.push_back({nums[idx], idx});
         push_heap(vec.begin(), vec.end(), greater<>());
       }

       return nums;
    }
};
