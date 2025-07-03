/*
    Leetcode Link               : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach-1 (Simulation)
//T.C : O(k)
//S.C : O(k)
class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while(s.size() < k){
            string temp = "";

            for(int i=0; i<s.size(); i++){
                if(s[i] >= 'a' && s[i] < 'z') temp += (s[i]+1);
                else if(s[i] == 'z')  temp += 'z';
            }

            s += temp; 
            // cout<<"temp: "<<temp<<" s: "<<s<<endl;
        }

        return s[k-1];
    }
};


//Approach-2 (bit observation to find shift)
//T.C : O(log(k-1))
//S.C : O(1)
class Solution {
public:
    char kthCharacter(int k) {
        int shift = __builtin_popcount(k-1);  // count the setbit(1 bit)
        // cout<<"shift: "<<shift<<endl;

        return 'a'+shift;
    }
};
