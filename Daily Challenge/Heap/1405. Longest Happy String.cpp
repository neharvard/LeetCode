/*
    Leetcode Link               : https://leetcode.com/problems/longest-happy-string
*/

/************************************************************ C++ ************************************************************/
//Approach (simple thought process - Max Heap)
//T.C : O(a+b+c)
//S.C : O(1)
class Solution {
public:
    typedef pair<int, char > P;
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue< P, vector<P> > pq; // Max Heap

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        // while(!pq.empty()) {
        //     auto it = pq.top();
        //     cout<<it.first<<" "<<it.second<<endl;
        //     pq.pop();
        // }
        
        int idx = 0;
        while(!pq.empty()){
            int currFreq = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            if(idx>1 && ans[idx-1] == currChar && ans[idx-2] == currChar){
                if(pq.empty()) break;

                int nxtFreq = pq.top().first;
                char nxtChar = pq.top().second;
                pq.pop();

                ans += nxtChar; idx++; nxtFreq--;
                if(nxtFreq > 0) pq.push({nxtFreq, nxtChar});
            } 
            else{
                ans += currChar; idx++; currFreq--;
            }

            if(currFreq > 0) pq.push({currFreq, currChar});
        }

        return ans;
    }
};
