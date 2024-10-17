/*
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/maximum-swap
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (using temporary string)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string temp = s;
        sort(temp.begin(), temp.end(), greater<>());
        // cout<<"s:"<<s<<" t:"<<temp<<endl;

        for (int i = 0; i < s.size(); i++) {
            int f = 0;
            if (s[i] != temp[i]) {
                for (int j = s.size() - 1; j > i; j--) {
                    if (s[j] == temp[i]) {
                        swap(s[j], s[i]);
                        f = 1;
                        break;
                    }
                }
                if (f) break;
            }
        }

        int ans = stoi(s);

        return ans;
    }
};


//Approach-2 (using space to store maxRight Indices)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int sz = s.size();

        vector<int>mxRight(sz);
        mxRight[sz-1] = sz-1;

        for(int i=sz-2; i>=0; i--){
            int idx = mxRight[i+1];
            mxRight[i] = (s[i] > s[idx]) ? i : mxRight[i+1];
        }
        // for(auto it:mxRight)cout<<it<<" ";cout<<endl;

        for(int i=0; i<sz; i++){
            int idx = mxRight[i];
            if(s[i] < s[idx]){
                swap(s[i], s[idx]);
                break;
            }
        }
      
        return stoi(s);
    }
};



//Approach-3 (using constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int sz = s.size();
        
        vector<int>mxRight(10, -1);
        for(int i=0; i<sz; i++){ 
            mxRight[s[i]-'0'] = i;
        }

        for(int i=0; i<sz; i++){
            for(int j=9; j>=0; j--){
                int idx = mxRight[j];
                if(idx!=-1 && s[i] < s[idx] && i < idx){
                    swap(s[i], s[idx]);
                    return stoi(s);
                }
            }
        }
      
        return num;
    }
};
