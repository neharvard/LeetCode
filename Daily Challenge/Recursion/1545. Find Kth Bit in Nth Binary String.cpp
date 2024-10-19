/*
    Leetcode Link               : https://leetcode.com/problems/find-kth-bit-in-nth-binary-string
*/


/************************************************************ C++ ************************************************/
//Approach-1:  BruteForce
//T.C : O(n * m)
//S.C : O(n)
class Solution {
public:
    char findKthBit(int n, int k) {
        string s, temp;
      
        for(int i=1; i<=n; i++){
            if(i == 1) s = "0";
            else{
                temp = s;
                s += "1";
                reverse(temp.begin(), temp.end());
                for(int j=0; j<temp.size(); j++){
                    if(temp[j] == '0') temp[j] = '1';
                    else temp[j] = '0';
                }

                s += temp; 
            }  //cout<<"i: "<<i<<" s:"<<s<<endl;
        }

        // cout<<"sz:"<<s.size()<<endl;
        char ans = s[k-1];
        return ans;
    }
};


//Approach-2:  Recursion
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    char findKthBit(int n, int k) {
        int length = pow(2,n) - 1;
        int mid = (length + 2 - 1) / 2;

        if(n == 1){ // base case
            return '0';
        }
        
        if(k < mid){ // left side
            return findKthBit(n-1, k);
        }
        else if(k == mid){
            return '1';
        }
        else { // right side
           char ch = findKthBit(n-1, (length-k)+1); // for handling reverse
           return (ch == '0') ? '1' : '0'; // for handing filpped
        }
    }
};
