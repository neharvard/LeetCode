/*
    Leetcode Link               : https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/
*/


/*************************************************************** C++ ***************************************************************/
//Priority Queue
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    typedef pair<char,int>P;

    struct comp{
        bool operator()(P &p1, P &p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }

            return p1.first > p2.first;
        }
    };
   
    string clearStars(string s) {
        int sz = s.size();
        priority_queue<P, vector<P>, comp> pq;

        for(int i=0; i<sz; i++){
            if(s[i] != '*'){
                pq.push({s[i], i});
            }
            else{
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
        }

        string ans = "";
        for(int i=0; i<sz; i++){
            if(s[i] != '*') ans += s[i];
        }
        
        return ans;
    }
};
