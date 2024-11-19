/*
    Leetcode Link                 : https://leetcode.com/problems/defuse-the-bomb
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n*|k|)
//S.C : O(1)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sz = code.size();
        vector<int>ans(sz, 0);

        if (k == 0) return ans;
      
        for(int i=0; i<sz; i++){
            if(k > 0){
                for(int j = i+1; j<=i+k; j++){
                    ans[i] += code[j % sz];
                }
            }
            else{
                for(int j = i - abs(k); j<i; j++){
                    ans[i] += code[(j + sz) % sz];
                }
            }
        }
      
        return ans;
    }
};



//Approach-2 (Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sz = code.size();
        vector<int> temp, ans(sz, 0);

        if (k == 0) return ans;

        temp = code;
        for (int i = 0; i < sz; i++) temp.push_back(code[i]);

        // for (auto& el : temp) cout << el << " ";cout << endl;

        long long sum = 0, cnt = 0;
        int n = temp.size();

        if (k > 0) {
            int i = 0, j = i + 1;
            while (i < sz) {
                while (cnt < k && j < n) {
                    sum += temp[j];
                    cnt++, j++;
                }

                if (i != 0) sum -= code[i];

                ans[i] = sum;
                cnt--, i++;
            }
        } 
        else {
            int i = sz - 1, j = n - 2;
            while (i >= 0) {
                while (cnt < abs(k) && j > 0) {
                    sum += temp[j];
                    cnt++, j--;
                }

                if (i != sz - 1) sum -= code[i];

                ans[i] = sum;
                cnt--, i--;
            }
        }
      
        return ans;
    }
};
