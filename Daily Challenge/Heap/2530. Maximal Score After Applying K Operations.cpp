/*
    Leetcode Link               : https://leetcode.com/problems/maximal-score-after-applying-k-operations
*/

/************************************************************ C++ ************************************************************/
//Approach- (Using Max Heap)
//T.C : O(N)
//S.C : O(N)
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0, num;
        priority_queue<int>pq;

        for(auto &it : nums) pq.push(it);

        while(k-- && !pq.empty()){
            num = pq.top(); ///cout<<"n1:"<<num<<endl;
            pq.pop();
            ans += num;
            num = (num+3-1)/3; ///cout<<"n2:"<<num<<endl;
            pq.push(num);
        }

        return ans;
    }
};
