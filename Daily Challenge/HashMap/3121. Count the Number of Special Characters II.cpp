/*
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/
    Part I of this problem      : http://youtube.com/post/UgkxA76EhTpRxCqK4apoG-YaaQ5Lao9VypAU?si=Gi0wKGIFA-kr9iaF
*/


/*********************************************************** C++ **************************************************/
//Approach (Track last occurrence of lowercase and first occurrence of uppercase)
//T.C : O(n)
//S.C : 
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int sz = word.size(), ans = 0;
        map<char,int>lowerIdx, upperIdx;

        for(int i=sz-1; i>=0; i--){
            if(word[i] >= 'a' && word[i] <= 'z') lowerIdx.insert({word[i], i});
        }
        // for(auto &it : lowerIdx) cout<<it.first<<" "<<it.second<<endl;

        for(int i=0; i<sz; i++){
            if(word[i] >= 'A' && word[i] <= 'Z') upperIdx.insert({word[i], i});

        }

        for(auto &it : upperIdx){
            int ch = it.first, idx = it.second;

            char c = tolower(ch); 
            // cout<<"c: "<<c<<endl;
            if(lowerIdx.find(c) != lowerIdx.end() && lowerIdx[c] < idx) ans++;
        }

        return ans;
    }
};
