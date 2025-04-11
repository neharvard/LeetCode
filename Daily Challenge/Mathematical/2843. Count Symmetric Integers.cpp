/*

    Leetcode Link                : https://leetcode.com/problems/count-symmetric-integers
*/


/****************************************************************** C++ ******************************************************************/
//Approach-1 (Brute Force)
//T.C : O((high-low+1)*d), where d  = number of digits
//S.C : O(d) for storing string
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

           for(int i=low; i<=high; i++){
            string s = to_string(i);
            int firstHalf = 0, lastHalf = 0;
            int sz = s.size();
            if(sz%2) continue;

            int j = 0;
            while(j < sz/2){
                firstHalf += (s[j]-'0');
                j++;
            }
            while(j < sz){
                lastHalf += (s[j] - '0');
                j++;
            }

            // cout<<"f:"<<firstHalf<<" s: "<<lastHalf<<endl;
            if(firstHalf == lastHalf) ans++;
        }
      
        return ans;
    }
};


//Approach-2 (Optimal using / and %)
//T.C : O(high-low+1)
//S.C : O(1)
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for(int i = low; i <= high; i++){
            if((i>10 && i<=99) && i%11 == 0) ans++;
            else if(i>1000 && i<=9999){
                int first = (i / 1000);
                int second = (i / 100) % 10;

                int third = (i / 10) % 10;
                int fourth = (i / 1) % 10;
                // cout<<"f:"<<first<<" s:"<<second<<" t:"<<third<<" fr:"<<fourth<<endl;

                if((first + second) == (third + fourth)) ans++;
            } 
            
        }

        return ans;
    }
};
