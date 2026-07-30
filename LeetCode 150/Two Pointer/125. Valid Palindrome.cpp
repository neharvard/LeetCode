/*
    Company Tags                : Amazon, Facebook, Microsoft, Twitter, Apple, Google, Paypal, Bloomberg, Adobe, InfoEdge
    Leetcode Link               : https://leetcode.com/problems/valid-palindrome/  
*/

//Approach-1: use extra space, BruteForce
//TC : O(n)
//SC : O(n)
class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size();
        string temp = "";

        for(int i=0; i<sz; i++){
            if(s[i] >= '0' && s[i] <= '9') temp += s[i];
            else if(isalpha(s[i])) temp += tolower(s[i]);
        }
        // cout<<"temp:"<<temp<<endl;
        
        int sz2 = temp.size();
        int i=0, j=sz2-1;

        while(i<j){
            if(temp[i] != temp[j]) return false;
            i++, j--;
        }

        return true;
    }
};


//Approach-2: check palindrome on the fly, don't use extra space
//TC : O(n)
//SC : O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size();
        int i=0,j=sz-1;
      
        while(i < j){
            while(i<j && !(s[i]>='0' && s[i]<='9') && !isalpha(s[i])){
                // cout<<"i:"<<i<<" s:"<<s[i]<<endl;
                i++;
            }
            while(i<j && !(s[j]>='0' && s[j]<='9') && !isalpha(s[j])){
                // cout<<"i:"<<j<<" s:"<<s[j]<<endl;
                j--;
            }

            char ch1 = tolower(s[i]);
            char ch2 = tolower(s[j]);
            // cout<<"ch1:"<<ch1<<" ch2:"<<ch2<<endl;

            if(ch1 != ch2) return false;
            i++, j--;
        }

        return true;
    }
};
