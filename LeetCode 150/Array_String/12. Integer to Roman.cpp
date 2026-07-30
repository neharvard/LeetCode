/*
    Company Tags                : Amazon, Facebook, Microsoft, Twitter, Apple, Google, Paypal, Bloomberg, Adobe, InfoEdge
    Leetcode Link               : https://leetcode.com/problems/integer-to-roman/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/convert-to-roman-no/1
    
*/
//Approach-1
class Solution {
public:
    string intToRoman(int num) {
        vector<int>v = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        int sz = v.size();
        string ans;
        while(num){
            int rem, times;
            string s;
            for(int i=0; i<sz; i++){
                if(num >= v[i]){
                    rem = num % v[i];
                    times = num / v[i];
                    s = symbol[i];
                    break;
                }
            }
            // cout<<"rem:"<<rem<<" t:"<<times<<" s: "<<s<<endl;
            num = rem;

            for(int i=1; i<=times; i++) ans += s;
        }

        return ans;    
    }
};


// More clean Code of Approach-1

class Solution {
public:
    string intToRoman(int num) {
        vector<int>v = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string>symbol = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        int i=0;
        string ans = "";
     
        while(num){
            while(num >= v[i]){
                num -= v[i];
                ans += symbol[i];
            }
            i++;
        }

        return ans;    
    }
};
