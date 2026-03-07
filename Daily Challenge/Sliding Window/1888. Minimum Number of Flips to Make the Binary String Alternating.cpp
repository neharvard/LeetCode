/*
    Company Tag                 : 
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating
*/


/*************************************************************** C++ *************************************************/
//Approach-1 (Sliding Window + modifying input s = s+s)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2 and s+=s
class Solution {
public:
    int minFlips(string s) {
        int sz = s.size();

        string s1, s2;
        s1 += '0', s2 += '1';
        for(int i=1; i<2*sz; i++){
            s1 += (s1[i-1] == '0' ? '1' : '0');
            s2 += (s2[i-1] == '0' ? '1' : '0');
        }

        s += s;
        // cout<<"s: "<<s<<" s1: "<<s1<<" s2: "<<s2<<endl;
        
        int ans = INT_MAX, f1 = 0, f2 = 0;
        int i=0, j=0;
        while(i<2*sz){
            if(s[i] != s1[i]) f1++;
            if(s[i] != s2[i]) f2++;

            if(i-j+1 > sz){
                if(s[j] != s1[j]) f1--;
                if(s[j] != s2[j]) f2--;
                j++;
            }

            if(i-j+1 == sz) ans = min({ans, f1, f2}); 
            i++;
        }

        // for(int i=0, j=0; i<sz+sz; i++){
        //     if(s[i] != s1[i]) f1++;
        //     if(s[i] != s2[i]) f2++;

        //     if(i >= (sz-1)){
        //         ans = min(ans,(min(f1, f2))); 
        //         // cout<<"f1:"<<f1<<" f2:"<<f2<<" a:"<<ans<<endl;
        //         if(s[j] != s1[j]) f1--;
        //         if(s[j] != s2[j]) f2--;
        //         j++;
        //     }
        // }

        return ans;
    }
};



//Approach-2 (Sliding Window + without modifying input)
//T.C : O(2*n) ~= O(n)
//S.C : O(2*n) for s1 and s2
class Solution {
public:
    int minFlips(string s) {
        int sz = s.size();

        string s1, s2;
        s1 += '0', s2 += '1';
        for(int i=1; i<2*sz; i++){
            s1 += (s1[i-1] == '0' ? '1' : '0');
            s2 += (s2[i-1] == '0' ? '1' : '0');
        }
        // cout<<"s: "<<s<<" s1: "<<s1<<" s2: "<<s2<<endl;
        
        int ans = INT_MAX, f1 = 0, f2 = 0;
        int i=0, j=0;
        while(i<2*sz){
            if(s[i%sz] != s1[i]) f1++;
            if(s[i%sz] != s2[i]) f2++;

            if(i-j+1 > sz){
                if(s[j%sz] != s1[j]) f1--;
                if(s[j%sz] != s2[j]) f2--;
                j++;
            }

            if(i-j+1 == sz) ans = min({ans, f1, f2}); 
            i++;
        }

        // for(int i=0, j=0; i<sz+sz; i++){
        //     if(s[i] != s1[i]) f1++;
        //     if(s[i] != s2[i]) f2++;

        //     if(i >= (sz-1)){
        //         ans = min(ans,(min(f1, f2))); 
        //         // cout<<"f1:"<<f1<<" f2:"<<f2<<" a:"<<ans<<endl;
        //         if(s[j] != s1[j]) f1--;
        //         if(s[j] != s2[j]) f2--;
        //         j++;
        //     }
        // }

        return ans;
    }
};
