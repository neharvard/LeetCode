/*
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/


/******************************************************* C++ *******************************************************/
//Approach (Brute Force All Possible Answers)
//T.C : O(n*k)
//S.C : O(2^k * k), storing 2^k substrings of length k each
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int totalSub = pow(2,k); //cout<<"t:"<<totalSub<<endl;
        int n = s.size();
        set<string>st;

        if(n < k) return false;

        for(int i=0; i<n-k+1; i++){
            string temp = s.substr(i, k); //cout<<"temp:"<<temp<<endl;
            st.insert(temp);
        }

        int sz = st.size(); //cout<<"sz: "<<sz<<endl;
        if(sz != totalSub) return false;

        return true;
    }
};
