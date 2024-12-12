/*
    Leetcode Link               : https://leetcode.com/problems/take-gifts-from-the-richest-pile
*/


/************************************************************ C++ ************************************************/
//Approach (Using max-heap)
//T.C : O(n + k*logn)
//S.C : O(n)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        long long sum = 0;
        for(auto &el : gifts){
            sum += el;
            pq.push(el);
        } 
        
        while(!pq.empty() && k--){
            int sq = sqrt(pq.top());
            // cout<<"k:"<<k<<" pq:"<<pq.top()<<" sq: "<<sq<<endl;

            sum -= pq.top(); // cout<<"s1: "<<sum<<" ";
            pq.pop();  
            pq.push(sq);
            sum += sq; // cout<<"s2: "<<sum<<endl;
        }

        return sum;
    }
};
