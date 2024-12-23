/*
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level
*/


/****************************************************** C++ ***************************************************/
//Approach - Simple BFS with hidden problem
//T.C : O(n + level * wlogw), level = total levels, w = number of nodes in a level
//S.C : O(n)
class Solution {
public:
    int solve(vector<int>& temp){
        map<int, int>mpNum;
        map<int, int>mpPos;

        for(int i=0; i<temp.size(); i++){
            mpNum[temp[i]] = i;
            mpPos[i] = temp[i];
        }
        sort(begin(temp), end(temp));
        
        int cnt = 0;
        for(int i=0; i<temp.size(); i++){
            if(mpNum[temp[i]] == i) continue;
            cnt++;

            int curr = temp[i];
            int old = mpPos[i];
            int currPos = i;
            int oldPos = mpNum[temp[i]];

            mpNum[old] = oldPos;
            mpPos[oldPos] = old;
        }

        return cnt;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue< TreeNode* > q;

        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp;
            // cout<<"sz:"<<sz<<endl;

            while(sz--){
                if(q.front()->left != nullptr) q.push(q.front()->left);
                if(q.front()->right != nullptr) q.push(q.front()->right);

                temp.push_back(q.front()->val);
                q.pop();
            }

            // for(auto &el : temp)cout<<el<<" "; cout<<endl;

            ans += solve(temp); 
        }

        return ans;
    }
};
