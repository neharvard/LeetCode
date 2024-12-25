/*
    Leetcode Link               : https://leetcode.com/problems/find-largest-value-in-each-tree-row
*/


/****************************************************** C++ ***************************************************/
//Approach - Simple BFS 
//T.C : O(level * wlogw), level = total levels, w = number of nodes in a level
//S.C : O(n)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue< TreeNode* > que; 
        if(root == 0) return ans;
        que.push(root);

        while(!que.empty()){
            int sz = que.size();  
            //cout<<"sz: "<<sz<<endl;
            int mx = INT_MIN;

            while(sz--){
                if(que.front()->left != nullptr) que.push(que.front()->left);
                if(que.front()->right != nullptr) que.push(que.front()->right);

                mx = max(mx, que.front()->val);
                que.pop();
            }
            // cout<<"mx:"<<mx<<endl;
            ans.push_back(mx);
        }

        return ans;
    }
};
