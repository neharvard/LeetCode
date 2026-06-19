/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=iH67r9BLpAw
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/coupon-code-validator
*/



/************************************************************ C++ *****************************************************/
//Approach - 1: (Using map, set and sorting)
//T.C : O(N × M) 
//S.C : O(n)
class Solution {
public:
    bool isValid(string& s){
        for(auto &it : s){
            // cout<<"it: "<<it<<endl;
            if(it >= 'A' && it <= 'Z') continue;
            else if(it >= 'a' && it <= 'z') continue;
            else if(it >= '0' && it <= '9') continue;
            else if(it == '_') continue;
            else return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int sz = code.size();
        set<string>bLine;

        bLine.insert("electronics");
        bLine.insert("grocery");
        bLine.insert("pharmacy");
        bLine.insert("restaurant");
        

        vector<string>ans;
        map<string,vector<string>>mp;
        for(int i=0; i<sz; i++){
            if(code[i] != "" && isValid(code[i])){ 
                // cout<<"c: "<<code[i]<<endl;
                if(bLine.find(businessLine[i]) != bLine.end()){
                    if(isActive[i]) mp[businessLine[i]].push_back(code[i]);
                }
            }
        }

        for(auto &it : mp){ 
            // cout<<"it: "<<it.first<<endl;
            sort(it.second.begin(), it.second.end());
            for(auto &el: it.second){
               ans.push_back(el);
                // cout<<el<<" "; cout<<endl;
            }
        }

        return ans;
    }
};



//Approach - 2: More Clearner Code (Using map and sorting)
//T.C : O(n*l + nlogn) where n = code.size() and l = average length of codes
//S.C : O(n)
class Solution {
public:
    bool isValid(string& code){
        if(code.empty()) return false;
        for(char &ch : code){
            if(!isalnum(ch) && ch != '_') return false;
        }
        
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,int>ump = {
           {"electronics", 0},
           {"grocery", 1},
           {"pharmacy", 2},
           {"restaurant", 3 }
        };

        vector<pair<int,string>>temp; //businessLineInt, code
        for(int i=0; i<code.size(); i++){
            if(isValid(code[i]) && ump.count(businessLine[i]) != 0 && isActive[i]){
                temp.push_back({ump[businessLine[i]], code[i]});
            }
        }

        sort(begin(temp), end(temp));
        vector<string>ans;
        for(auto &it : temp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
