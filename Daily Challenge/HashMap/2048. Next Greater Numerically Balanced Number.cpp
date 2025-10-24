/*
    Company Tags                : Adobe
    Leetcode Link               : https://leetcode.com/problems/next-greater-numerically-balanced-number
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Doing simulation)
//T.C : O(L-n), where L = 1224444
//S.C : O(1)
class Solution {
public:
    bool balanced(int num){
        // string s = to_string(num);
        // unordered_map<int,int>freq;
        // for(auto &it : s){
        //     int x = it-'0'; 
        //     freq[x]++;
        // }
        // for(auto &it : s){
        //     int x = it-'0'; 
        //     if(x == freq[x]) continue;
        //     return false;
        // }
        // return true;

        vector<int>freq(10); //cout<<"Num: "<<num<<endl;
        while(num > 0){
            freq[num%10]++;
            num /= 10;
        }
        for(int i = 0; i<10; i++){ //cout<<"i: "<<i<<" "<<freq[i]<<endl;
            if(freq[i] != 0 && freq[i] != i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int num;
        for(num = n+1; num <= 1224444; num++){
           if(balanced(num)) break;
        }
        
        return num;
    }
};
