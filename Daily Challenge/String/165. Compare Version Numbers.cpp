/*
    Company Tags                : Apple, Microsoft (They check how easily you are able to manage strict corner cases)
    Leetcode Link               : https://leetcode.com/problems/compare-version-numbers/
*/


/****************************************************************** C++ ******************************************************************/
//Approach: 
//T.C : O(m+n)
//S.C : O(m+n)
class Solution {
public:
    #define pb push_back
    int compareVersion(string version1, string version2) {
        int sz1 = version1.size(), sz2 = version2.size();
        vector<int>v1(501, 0), v2(501,0);
        string temp = "";
        
        int j = 0;
        for(int i=0; i<sz1; i++){
            if(version1[i] == '.'){
                int x = stoi(temp); 
                v1[j] = x;
                j++;
                temp.clear();
                continue;
            }

            temp += version1[i];    
        }
        if(temp != ""){ 
            int x = stoi(temp);
            v1[j] = x;
        }

        temp = "", j = 0;
        for(int i=0; i<sz2; i++){
            if(version2[i] == '.'){
                int x = stoi(temp); 
                v2[j] = x;
                j++;
                temp.clear();
                continue;
            }

            temp += version2[i];
        }
        if(temp != ""){ 
            int x = stoi(temp);
            v2[j] = x;
        }
        
        int v1Sz = v1.size(), v2Sz = v2.size();
        for(int i=0; i<=500; i++){ 
            //cout<<"v1:"<<v1[i]<<" v2:"<<v2[i]<<endl;
            if(v1[i] < v2[i]) return -1;
            else if(v1[i] > v2[i]) return 1;
        }


        return 0;
    }
};
