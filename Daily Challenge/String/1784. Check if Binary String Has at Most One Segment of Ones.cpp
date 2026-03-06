/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones
*/


/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (simple traverse and check)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        int sz = s.size();
        int oneSeg = 0;

        for(int i=0; i<sz; i++){
            if(s[i] == '1'){
                while(i<sz && s[i] == '1'){
                   i++;
                }
                oneSeg++;
            }
        }
        // cout<<"seg: "<<oneSeg<<endl;


        return (oneSeg == 1)? true : false;
    }
};
