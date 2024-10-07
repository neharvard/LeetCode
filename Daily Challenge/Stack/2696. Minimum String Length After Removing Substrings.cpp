/*
    Leetcode Link               : https://leetcode.com/problems/minimum-string-length-after-removing-substrings
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (BruteForce)
//T.C : O(N^2)
//S.C : O(1)
class Solution {
public:
    int minLength(string s) {
          for(int i=0; i<s.size(); ){
              int ok = 0;
              for(int j=0; j<s.size()-1; j++){
                  if(s[j] == 'A' && s[j+1] == 'B'){
                      s.erase(s.begin()+j, s.begin()+j+2);
                      ok = 1;
                  }
                  else if(s[j]=='C' && s[j+1] == 'D'){
                      s.erase(s.begin()+j, s.begin()+j+2);
                      ok = 1;
                  }
                  if(s.size()<2){ok = 1; break;}
              }

              if(!ok) break;
          }
          return s.size();
    }
};


//Approach-2 (Using Stack)
//T.C : O(N)
//S.C : O(N)
class Solution {
public:
    int minLength(string s) {
        int sz = s.size();
        stack<char> st;
        for (int i = 0; i < sz; i++) {
            int ok = 0;
            if (s[i] == 'B') {
                if (!st.empty() && st.top() == 'A') {
                    st.pop();
                    ok = 1;
                }
            } else if (s[i] == 'D') {
                if (!st.empty() && st.top() == 'C') {
                    st.pop();
                    ok = 1;
                }
            }
            if (!ok) st.push(s[i]);
        }
        return st.size();
    }
};
