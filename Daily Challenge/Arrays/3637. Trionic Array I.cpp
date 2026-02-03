/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/trionic-array-i
*/


/*********************************************************** C++ **************************************************/
//Approach:1 (Simply simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int flg = 0;
        int sz = nums.size();

        for(int i=0; i<sz; i++){
            bool ok = false;
            while(flg == 0 && i<sz-1 && nums[i] < nums[i+1]){
                i++; 
                ok = true;
            }
            if(ok && flg == 0){
                flg++; 
                if(i != sz) i--;  
                continue;
            } 
            else if(!ok && flg == 0) break;        

            while(flg == 1 && i<sz-1 && nums[i] > nums[i+1]){
                i++;
                ok = true;
            }
            if(ok && flg == 1){
                flg++;  
                if(i != sz) i--; 
                continue;
            } 
            else if(!ok && flg == 1) break;          

            while(flg == 2 && i<sz-1 && nums[i] < nums[i+1]){
                i++;
                ok = true;
            }
            if(ok && flg == 2 && i == sz-1){ 
                flg++;  
            } 
            else break;      
        }
        // cout<<"flg: "<<flg<<endl;

        if(flg == 3) return true;
        return false;
    }
};



//Approach:2 (Simply simulation) [More Optimized & Clean Code]
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int sz = nums.size();
        int i=0;

        while(i<sz-1 && nums[i] < nums[i+1]) i++;
        if(i == 0 || i==sz-1) return false;

        while(i<sz-1 && nums[i] > nums[i+1]) i++;
        if(i == sz-1) return false;

        while(i<sz-1 && nums[i] < nums[i+1]) i++;
        
        return i == sz-1;
    }
};
